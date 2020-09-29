#ifndef REQUEST_H
#define REQUEST_H

#include "date.h"
#include "list_record.h"
#include "list_str.h"
#include "record.h"
#include "str.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 4
#define MAX_TIMESTAMP 40
#define MAX_RES_SIZE 20
#define BASE 10
#define RADIUS_RATIO 10000

#define LOG 0
#define DAILY 1
#define MONTHLY 2
#define GLOBAL 3

#define OZONE 0
#define PARTICULLATE_MATTER 1
#define CARBON_MONOXIDE 2
#define SULFURE_DIOXIDE 3
#define NITROGEN_DIOXIDE 4

typedef struct Request Request;
struct Request {
    int    metric;
    Date   timestamp;
    int    type;
    double longitude;
    double latitude;
    double radius;
};

typedef struct Result Result;
struct Result {
    double avg;
    int    min;
    int    max;
};

//----------------------------------------------

void fetch_command(ListRec * record_list, char * command);

Request extract_request_data(char * command);

void add_data_to_list(ListStr * res_list, Record record, Request request);

void get_metric(ListStr * list, Request * request);

void get_type(ListStr * list, Request * request);

void get_timestamp(ListStr * list, Request * request);

void get_coords(ListStr * list, Request * request);

void process_result(ListStr * res_list);

void display_result(Result result);

void display_request(Request request);

#endif
