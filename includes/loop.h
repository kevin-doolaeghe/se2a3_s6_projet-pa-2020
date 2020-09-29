#ifndef LOOP_H
#define LOOP_H

#include "list_record.h"
#include "list_str.h"
#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 50

//----------------------------------------------

void command_usage();

void interactive_mode(ListRec * record_list);

void batch_mode(ListRec * record_list, ListStr * command_list);

#endif
