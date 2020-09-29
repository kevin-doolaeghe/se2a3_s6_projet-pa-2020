#include "../includes/read_file.h"

FILE * get_file_instance(char * file_name, char * mode) {
    FILE * fp;
    fp = fopen(file_name, mode);

    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        return NULL;
    }

    return fp;
}

void destroy_file_instance(FILE * fp) { fclose(fp); }

void read_command_file(FILE * fp, ListStr * command_list) {
    clear_list(command_list);
    char line[MAX_LINE_SIZE];

    while (fscanf(fp, "%[^\n]\n", line) != EOF) {
        // printf("%s\n", line);
        append_str_to_list(command_list, line);
    }

    if (feof(fp)) { printf("Common end of file reading.\n"); }
    if (ferror(fp)) { printf("An error occurred while reading the file !\n"); }
}

void read_record_from_file_list(ListStr * file_list, ListRec * record_list) {
    for (int i = 0; i < file_list->size; i++) {
        if (strstr(file_list->str_list[i].data, ".csv") != NULL &&
            strstr(file_list->str_list[i].data, "pollutionData") != NULL) {
            // printf("File to read: %s\n", file_list->str_list[i].data);

            FILE * fp = get_file_instance(file_list->str_list[i].data, "r");
            read_record_file(fp, record_list);
            destroy_file_instance(fp);
        }
    }
}

void read_record_file(FILE * fp, ListRec * record_list) {
    Record record;

    char line[MAX_LINE_SIZE];
    int  line_count = 0;

    while (fscanf(fp, "%[^\n]\n", line) != EOF) {
        // printf("%s\n", line);

        if (line_count != 0) {
            decode_line(line, &record);
            append_to_record_list(record_list, record);
        }
        line_count++;
    }

    if (feof(fp)) { printf("Common end of file reading : %d lines read.\n", line_count); }
    if (ferror(fp)) { printf("An error occurred while reading the file !\n"); }
}

void decode_line(char * line, Record * record) {
    char ** list = NULL;
    list         = malloc((RECORD_ITEM_COUNT + 1) * sizeof(char *));

    split_cstr(line, ",", list);

    record->ozone               = (int) strtol(list[OZONE_ID], NULL, BASE);
    record->particullate_matter = (int) strtol(list[PARTICULLATE_MATTER_ID], NULL, BASE);
    record->carbon_monoxide     = (int) strtol(list[CARBON_MONOXIDE_ID], NULL, BASE);
    record->sulfure_dioxide     = (int) strtol(list[SULFURE_DIOXIDE_ID], NULL, BASE);
    record->nitrogen_dioxide    = (int) strtol(list[NITROGEN_DIOXIDE_ID], NULL, BASE);
    record->longitude           = strtod(list[LONGITUDE_ID], NULL);
    record->latitude            = strtod(list[LATITUDE_ID], NULL);
    record->timestamp           = build_date(list[TIMESTAMP_ID]);

    free(list);
    list = NULL;
}
