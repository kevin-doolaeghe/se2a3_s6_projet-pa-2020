#ifndef LIST_RECORD_H
#define LIST_RECORD_H

#include "date.h"
#include "record.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CellRec CellRec;
struct CellRec {
    CellRec * next;
    Record    record;
};

typedef CellRec * ListRec;
typedef CellRec * PtCellRec;

//----------------------------------------------

PtCellRec allocate_record(Record record);

void append_to_record_list(ListRec * list, Record record);

void delete_last_record(ListRec * list);

void delete_record_list(ListRec * list);

int size_of_record_list(ListRec list);

bool search_record(ListRec list, Record record);

void add_record_to_list(ListRec * list, Record record);

void display_record_list(ListRec list);

void copy_record_list(ListRec * src, ListRec * dst);

#endif
