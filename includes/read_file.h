#ifndef READ_FILE_H
#define READ_FILE_H

#include "list_record.h"
#include "list_str.h"
#include "record.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 120
#define RECORD_ITEM_COUNT 8

#define BASE 10

#define OZONE_ID 0
#define PARTICULLATE_MATTER_ID 1
#define CARBON_MONOXIDE_ID 2
#define SULFURE_DIOXIDE_ID 3
#define NITROGEN_DIOXIDE_ID 4
#define LONGITUDE_ID 5
#define LATITUDE_ID 6
#define TIMESTAMP_ID 7

//----------------------------------------------

FILE * get_file_instance(char * file_name, char * mode);

void destroy_file_instance(FILE * fp);

void read_command_file(FILE * fp, ListStr * command_list);

void read_record_from_file_list(ListStr * file_list, ListRec * record_list);

void read_record_file(FILE * fp, ListRec * record_list);

void decode_line(char * line, Record * record);

#endif
