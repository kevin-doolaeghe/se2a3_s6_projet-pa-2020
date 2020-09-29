#include "../includes/loop.h"

void command_usage() { printf("usage: metric [opt] type [longitude latitude radius]\n"); }

// Interactive mode
void interactive_mode(ListRec * record_list) {
    char command[MAX_COMMAND_SIZE];

    printf("Interactive mode :\n");
    do {
        printf("> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strlen(command) - 1] = '\0';

        if (!strcmp(command, "help")) { command_usage(); }
        if (!strcmp(command, "display")) { display_record_list(*record_list); }

        fetch_command(record_list, command);
    } while (strcmp(command, "quit") != 0);
    printf("Bye !\n");
}

// Batch mode
void batch_mode(ListRec * record_list, ListStr * command_list) {
    printf("Batch mode :\n");
    for (int i = 0; i < command_list->size; i++) {
        printf("> ");
        print_str(&(command_list->str_list[i]));

        fetch_command(record_list, command_list->str_list[i].data);

        getchar();
    }
    printf("Bye !\n");
}
