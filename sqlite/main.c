#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "input.h"
#include "sqlite_mem.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND,
  PREPARE_NEGATIVE_ID,
  PREPARE_STRING_TOO_LONG,
  PREPARE_SYNTAX_ERROR
} MetaCommandResult;
void print_prompt() { printf("db > "); }

MetaCommandResult do_meta_command(InputBuffer* input_buffer,Table *table) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    close_input_buffer(input_buffer);
    db_close(table);
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}

PrepareResult prepare_statement(InputBuffer* input_buffer,
                                Statement* statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    char* keyword = strtok(input_buffer->buffer, " ");
    char* id_string = strtok(NULL, " ");
    char* username = strtok(NULL, " ");
    char* email = strtok(NULL, " ");
    if (id_string == NULL || username == NULL || email == NULL) {
       return PREPARE_SYNTAX_ERROR;
    }
    int id = atoi(id_string);
    if (id < 0) {
       return PREPARE_NEGATIVE_ID;
    }
    if (strlen(username) > COLUMN_USERNAME_SIZE) {
       return PREPARE_STRING_TOO_LONG;
    }
    if (strlen(email) > COLUMN_EMAIL_SIZE) {
       return PREPARE_STRING_TOO_LONG;
    }
    statement->row_to_insert.id = id;
    strcpy(statement->row_to_insert.username, username);
    strcpy(statement->row_to_insert.email, email);
    return PREPARE_SUCCESS;
    return PREPARE_SUCCESS;
  }
  if (strcmp(input_buffer->buffer, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}

int main(int argc, char* argv[]) {
   if (argc < 2) {
     printf("Must supply a database filename.\n");
     exit(EXIT_FAILURE);
   }
   char* filename = argv[1];
   Table* table = db_open(filename);
   InputBuffer* input_buffer = new_input_buffer();
   while (true) {
     print_prompt();
     read_input(input_buffer);
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    } else {
        printf("Unrecognized command '%s'.\n", input_buffer->buffer);
         if (input_buffer->buffer[0] == '.') {
           switch (do_meta_command(input_buffer,table)) {
             case (META_COMMAND_SUCCESS):
               continue;
             case (META_COMMAND_UNRECOGNIZED_COMMAND):
               printf("Unrecognized command '%s'\n", input_buffer->buffer);
               continue;
             case (PREPARE_NEGATIVE_ID):
               printf("ID must be positive.\n");
               continue;
             case (PREPARE_STRING_TOO_LONG):
               printf("String is too long.\n");
               continue;
             case (PREPARE_SYNTAX_ERROR):
               printf("Syntax error. Could not parse statement.\n");
               continue;
          }
        }
        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
          case (PREPARE_SUCCESS):
            break;
          case (PREPARE_UNRECOGNIZED_STATEMENT):
            printf("Unrecognized keyword at start of '%s'.\n",
                   input_buffer->buffer);
            continue;
        }
        execute_statement(&statement,table);
        printf("Executed.\n");
    }
   }
 }
