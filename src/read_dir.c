#include "../includes/read_dir.h"

DIR * get_dir_instance(char * folder_name) {
    DIR * fd;

    fd = opendir(folder_name);
    if (fd == NULL) {
        perror("Unable to read directory");
        return NULL;
    }

    return fd;
}

void destroy_dir_instance(DIR * fd) { closedir(fd); }

void read_dir(DIR * fd, ListStr * file_list) {
    clear_list(file_list);

    struct dirent * entry;

    while ((entry = readdir(fd))) {
        struct stat buffer;
        int         status;
        status = lstat(entry->d_name, &buffer);

        // printf("* %s\n", entry->d_name);

        // Absolute path needed with macro S_ISREG
        if (status == 0 && S_ISREG(buffer.st_mode)) {
            append_str_to_list(file_list, entry->d_name);
        }
    }
}
