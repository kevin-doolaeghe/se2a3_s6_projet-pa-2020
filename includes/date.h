#ifndef DATE_H
#define DATE_H

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OLDER 1
#define EARLIER (-1)
#define EQUAL 0

#define BASE 10

typedef struct Date Date;
struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

//----------------------------------------------

Date build_date(char * timestamp);

void display_date(Date date);

int compare_date(Date reference, Date date);

#endif
