#include "../includes/record.h"

void display_record(Record record) {
    printf("----------------------------------------\n");
    printf("ozone:\t\t\t%d\n", record.ozone);
    printf("particullate_matter:\t%d\n", record.particullate_matter);
    printf("carbon_monoxide:\t%d\n", record.carbon_monoxide);
    printf("sulfure_dioxide:\t%d\n", record.sulfure_dioxide);
    printf("nitrogen_dioxide:\t%d\n", record.nitrogen_dioxide);
    printf("longitude:\t\t%f\n", record.longitude);
    printf("latitude:\t\t%f\n", record.latitude);
    printf("timestamp:\t\t");
    display_date(record.timestamp);
}

int compare_record(Record reference, Record record) {
    return compare_date(reference.timestamp, record.timestamp);
}
