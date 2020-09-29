#ifndef RECORD_H
#define RECORD_H

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record Record;
struct Record {
    int    ozone;
    int    particullate_matter;
    int    carbon_monoxide;
    int    sulfure_dioxide;
    int    nitrogen_dioxide;
    double longitude;
    double latitude;
    Date   timestamp;
};

//----------------------------------------------

void display_record(Record record);

int compare_record(Record reference, Record record);

#endif
