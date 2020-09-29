#include "../includes/list_record.h"
#include "../includes/list_str.h"
#include "../includes/loop.h"
#include "../includes/read_dir.h"
#include "../includes/read_file.h"
#include "../includes/utils.h"

void program_usage() { printf("usage: ./project data_dir [command_file]\n"); }

// Main function
int main(int argc, char ** argv) {
    if (argc == 2 || argc == 3) {
        // Read file list
        DIR *   fd = get_dir_instance(argv[1]);
        ListStr file_list;
        init_list_str(&file_list);
        read_dir(fd, &file_list);

        // Read record list
        ListRec record_list = NULL;
        read_record_from_file_list(&file_list, &record_list);

        // Check mode
        if (argc == 3) { // Batch mode
            // Read command list
            FILE *  fp = get_file_instance(argv[2], "r");
            ListStr command_list;
            init_list_str(&command_list);
            read_command_file(fp, &command_list);

            batch_mode(&record_list, &command_list);

            destroy_list_str(&command_list);
            destroy_file_instance(fp);
        } else { // Interactive mode
            interactive_mode(&record_list);
        }

        // Clean allocated data
        delete_record_list(&record_list);
        destroy_list_str(&file_list);
        destroy_dir_instance(fd);
    } else {
        program_usage();
        return -1;
    }

    return 0;
}
