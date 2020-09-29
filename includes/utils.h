#ifndef UTILS_H
#define UTILS_H

#include "list_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------

void split_cstr(char * str, const char * delim, char ** list);

void split(char * str, const char * delim, ListStr * list);

#endif
