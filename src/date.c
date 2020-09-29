#include "../includes/date.h"

Date build_date(char * timestamp) {
    Date result;

    ListStr tmp;
    ListStr date;
    ListStr time;
    init_list_str(&tmp);
    init_list_str(&date);
    init_list_str(&time);

    split(timestamp, " ", &tmp);

    split(tmp.str_list[0].data, "-", &date);
    result.year  = (int) strtol(date.str_list[0].data, NULL, BASE);
    result.month = (int) strtol(date.str_list[1].data, NULL, BASE);
    if (date.size > 2) {
        result.day = (int) strtol(date.str_list[2].data, NULL, BASE);
    } else {
        result.day = -1;
    }

    if (tmp.size > 1) {
        split(tmp.str_list[1].data, ":", &time);
        result.hour   = (int) strtol(time.str_list[0].data, NULL, BASE);
        result.minute = (int) strtol(time.str_list[1].data, NULL, BASE);
        result.second = (int) strtol(time.str_list[2].data, NULL, BASE);
    } else {
        result.hour   = -1;
        result.minute = -1;
        result.second = -1;
    }

    destroy_list_str(&tmp);
    destroy_list_str(&date);
    destroy_list_str(&time);

    return result;
}

void display_date(Date date) {
    if (date.year != -1) { printf("%d", date.year); }
    if (date.year != -1 && date.month != -1) { printf("-"); }
    if (date.month != -1) { printf("%d", date.month); }
    if ((date.year != -1 || date.month != -1) && date.day != -1) { printf("-"); }
    if (date.day != -1) { printf("%d", date.day); }

    if ((date.year != -1 || date.month != -1 || date.day != -1) &&
        (date.hour != -1 || date.minute != -1 || date.second != -1)) {
        printf(" ");
    }

    if (date.hour != -1) { printf("%d", date.hour); }
    if (date.hour != -1 && date.minute != -1) { printf(":"); }
    if (date.minute != -1) { printf("%d", date.minute); }
    if ((date.hour != -1 || date.minute != -1) && date.second != -1) { printf(":"); }
    if (date.second != -1) { printf("%d", date.second); }
    printf("\n");
}

int compare_date(Date reference, Date date) {
    if (reference.year != -1 && date.year != -1) {
        if (reference.year < date.year) { return EARLIER; }
        if (reference.year > date.year) { return OLDER; }
    }

    if (reference.month != -1 && date.month != -1) {
        if (reference.month < date.month) { return EARLIER; }
        if (reference.month > date.month) { return OLDER; }
    }

    if (reference.day != -1 && date.day != -1) {
        if (reference.day < date.day) { return EARLIER; }
        if (reference.day > date.day) { return OLDER; }
    }

    if (reference.hour != -1 && date.hour != -1) {
        if (reference.hour < date.hour) { return EARLIER; }
        if (reference.hour > date.hour) { return OLDER; }
    }

    if (reference.minute != -1 && date.minute != -1) {
        if (reference.minute < date.minute) { return EARLIER; }
        if (reference.minute > date.minute) { return OLDER; }
    }

    if (reference.second != -1 && date.second != -1) {
        if (reference.second < date.second) { return EARLIER; }
        if (reference.second > date.second) { return OLDER; }
    }

    return EQUAL;
}
