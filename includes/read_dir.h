#ifndef READ_DIR_H
#define READ_DIR_H

#include "list_str.h"
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

//----------------------------------------------

DIR * get_dir_instance(char * folder_name);

void destroy_dir_instance(DIR * fd);

void read_dir(DIR * fd, ListStr * file_list);

#endif
