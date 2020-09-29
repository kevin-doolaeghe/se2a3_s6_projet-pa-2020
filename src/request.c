#include "../includes/request.h"

void fetch_command(ListRec * record_list, char * command) {
    // printf("(1) Fetching command..\n");

    Request request = extract_request_data(command);
    // display_request(request);

    if (request.metric != -1) {
        PtCellRec ptr = *record_list;
        ListStr   res_list;
        init_list_str(&res_list);

        while (ptr != NULL) {
            if (request.radius != -1) {
                request.radius /= RADIUS_RATIO;
                if (ptr->record.longitude < (request.longitude + request.radius) &&
                    ptr->record.longitude > (request.longitude - request.radius) &&
                    ptr->record.latitude < (request.latitude + request.radius) &&
                    ptr->record.latitude > (request.latitude - request.radius)) {
                    if (compare_date(request.timestamp, ptr->record.timestamp) == EQUAL) {
                        add_data_to_list(&res_list, ptr->record, request);
                    }
                }
            } else {
                if (compare_date(request.timestamp, ptr->record.timestamp) == EQUAL) {
                    add_data_to_list(&res_list, ptr->record, request);
                }
            }

            ptr = ptr->next;
        }

        process_result(&res_list);
        destroy_list_str(&res_list);
    }
}

void add_data_to_list(ListStr * res_list, Record record, Request request) {
    char res[MAX_RES_SIZE];

    switch (request.type) {
        case OZONE:
            sprintf(res, "%d", record.ozone);
            break;
        case PARTICULLATE_MATTER:
            sprintf(res, "%d", record.particullate_matter);
            break;
        case CARBON_MONOXIDE:
            sprintf(res, "%d", record.carbon_monoxide);
            break;
        case SULFURE_DIOXIDE:
            sprintf(res, "%d", record.sulfure_dioxide);
            break;
        case NITROGEN_DIOXIDE:
            sprintf(res, "%d", record.nitrogen_dioxide);
            break;
    }

    append_str_to_list(res_list, res);
}

Request extract_request_data(char * command) {
    // printf("(2) Extracting request data..\n");

    Request request;

    ListStr list;
    init_list_str(&list);

    split(command, " ", &list);

    get_metric(&list, &request);
    if (request.metric != -1) {
        get_type(&list, &request);
        if (request.type != -1) {
            get_timestamp(&list, &request);
            get_coords(&list, &request);
        }
    }

    destroy_list_str(&list);

    return request;
}

void get_metric(ListStr * list, Request * request) {
    if (list->size > 1) {
        if (!strcmp(to_string(list->str_list[0]), "log")) {
            request->metric = LOG;
        } else if (!strcmp(to_string(list->str_list[0]), "daily")) {
            request->metric = DAILY;
        } else if (!strcmp(to_string(list->str_list[0]), "monthly")) {
            request->metric = MONTHLY;
        } else if (!strcmp(to_string(list->str_list[0]), "global")) {
            request->metric = GLOBAL;
        } else {
            request->metric = -1;
        }
    } else {
        request->metric = -1;
    }
}

void get_type(ListStr * list, Request * request) {
    int i = 1;
    if (request->metric == GLOBAL) { i--; }
    if (request->metric == LOG) { i++; }

    if (list->size > 1 + i) {
        if (!strcmp(to_string(list->str_list[1 + i]), "ozone")) {
            request->type = OZONE;
        } else if (!strcmp(to_string(list->str_list[1 + i]), "particullate_matter")) {
            request->type = PARTICULLATE_MATTER;
        } else if (!strcmp(to_string(list->str_list[1 + i]), "carbon_monoxide")) {
            request->type = CARBON_MONOXIDE;
        } else if (!strcmp(to_string(list->str_list[1 + i]), "sulfure_dioxide")) {
            request->type = SULFURE_DIOXIDE;
        } else if (!strcmp(to_string(list->str_list[1 + i]), "nitrogen_dioxide")) {
            request->type = NITROGEN_DIOXIDE;
        } else {
            request->type = -1;
        }
    } else {
        request->type = -1;
    }
}

void get_timestamp(ListStr * list, Request * request) {
    if (request->metric != GLOBAL) {
        if (request->metric == LOG) {
            char * timestamp = (char *) malloc(MAX_TIMESTAMP * sizeof(char));
            strcpy(timestamp, to_string(list->str_list[1]));
            strcat(timestamp, " ");
            strcat(timestamp, to_string(list->str_list[2]));
            request->timestamp = build_date(timestamp);
            free(timestamp);
        } else {
            request->timestamp = build_date(to_string(list->str_list[1]));
        }
    } else {
        request->timestamp.year   = -1;
        request->timestamp.month  = -1;
        request->timestamp.day    = -1;
        request->timestamp.hour   = -1;
        request->timestamp.minute = -1;
        request->timestamp.second = -1;
    }
}

void get_coords(ListStr * list, Request * request) {
    int i = 1;
    if (request->metric == GLOBAL) { i--; }
    if (request->metric == LOG) { i++; }

    if (list->size > 3 + i) {
        request->longitude = strtod(to_string(list->str_list[2 + i]), NULL);
        request->latitude  = strtod(to_string(list->str_list[3 + i]), NULL);
        request->radius    = strtod(to_string(list->str_list[4 + i]), NULL);
    } else {
        request->longitude = -1;
        request->latitude  = -1;
        request->radius    = -1;
    }
}

void process_result(ListStr * res_list) {
    // printf("(3) Processing result..\n");

    if (res_list->size != 0) {
        double sum = 0;
        int    min = (int) strtol(to_string(res_list->str_list[0]), NULL, BASE);
        int    max = (int) strtol(to_string(res_list->str_list[0]), NULL, BASE);

        int current = 0;

        for (int i = 0; i < res_list->size; i++) {
            current = (int) strtol(to_string(res_list->str_list[i]), NULL, BASE);
            sum += current;
            if (current < min) { min = current; }
            if (current > max) { max = current; }
        }

        Result res;
        res.avg = sum / res_list->size;
        res.min = min;
        res.max = max;

        display_result(res);
    }
}

void display_result(Result result) { printf("%f %d %d\n", result.avg, result.min, result.max); }

void display_request(Request request) {
    printf("----------------------------\n");
    printf("metric: %d\n", request.metric);
    printf("date: ");
    display_date(request.timestamp);
    printf("type: %d\n", request.type);
    printf("longitude: %f\n", request.longitude);
    printf("latitude: %f\n", request.latitude);
    printf("radius: %f\n", request.radius);
}
