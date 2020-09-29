#include "../includes/utils.h"

void split_cstr(char * str, const char * delim, char ** list) {
    int    i;
    char * tmp   = NULL;
    char * token = NULL;

    for (i = 0, tmp = str;; i++, tmp = NULL) {
        token = strtok(tmp, delim);
        if (token == NULL) { break; }

        // printf("%d: %s\n", i, token);
        list[i] = token;
    }
}

void split(char * str, const char * delim, ListStr * list) {
    clear_list(list);

    int    i;
    char * tmp   = NULL;
    char * token = NULL;

    for (i = 0, tmp = str;; i++, tmp = NULL) {
        token = strtok(tmp, delim);
        if (token == NULL) { break; }

        // printf("%d: %s\n", i, token);
        append_str_to_list(list, token);
    }
}
