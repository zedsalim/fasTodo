#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 255

FILE *f_write;
FILE *f_read;
FILE *f_tmp;

void addTodo(char buffer[]) {
  f_write = fopen("todo.txt", "a");
  if (f_write == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
  printf("Enter your TODO: ");
  fgets(buffer, MAX_STRING_SIZE, stdin);
  fputs(buffer, f_write);
  fclose(f_write);
}

void printTodo(char buffer[]) {
  f_read = fopen("todo.txt", "r");
  if (f_read == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
  int i = 0;
  while (fgets(buffer, MAX_STRING_SIZE, f_read) != NULL) {
    i++;
    printf("%2d - %s", i, buffer);
  }

  fclose(f_read);
}

int countTodo() {
  int i = 0;
  char tmp_buffer[MAX_STRING_SIZE];
  FILE *tmp_f_read = fopen("todo.txt", "r");
  if (tmp_f_read == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
  while (fgets(tmp_buffer, MAX_STRING_SIZE, tmp_f_read) != NULL) {
    i++;
  }
  fclose(tmp_f_read);
  return i;
}

void markTodoByLineNumber(char buffer[]) {
  f_read = fopen("todo.txt", "r");
  f_tmp = fopen("tmp_todo.txt", "w");
  if (f_read == NULL || f_tmp == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
  int todo_list_size = countTodo();
  char org_file_name[] = "todo.txt";
  char tmp_file_name[] = "tmp_todo.txt";
  int line_to_delete = 0;
  printf("Which todo did you finish? (enter the line number): ");
  if (scanf("%d", &line_to_delete) != 1 ||
      (line_to_delete < 1 || line_to_delete > todo_list_size)) {
    printf("Invalid input. Try again.\n");
  } else {
    int i = 0;
    while (fgets(buffer, MAX_STRING_SIZE, f_read) != NULL) {
      i++;
      if (i != line_to_delete) {
        fputs(buffer, f_tmp);
      }
    }
    fclose(f_read);
    fclose(f_tmp);
    remove(org_file_name);
    rename(tmp_file_name, org_file_name);
  }
}

void updateTodoByLineNumber(char buffer[]) {
  f_read = fopen("todo.txt", "r");
  f_tmp = fopen("tmp_todo.txt", "w");
  if (f_read == NULL || f_tmp == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
  int todo_list_size = countTodo();
  char org_file_name[] = "todo.txt";
  char tmp_file_name[] = "tmp_todo.txt";
  int line_to_update = 0;
  printf("Which todo you want to update? (enter the line number): ");
  if (scanf("%d", &line_to_update) != 1 ||
      (line_to_update < 1 || line_to_update > todo_list_size)) {
    printf("Invalid input. Try again.\n");
  } else {
    getchar();
    int i = 0;
    while (fgets(buffer, MAX_STRING_SIZE, f_read) != NULL) {
      i++;
      if (i == line_to_update) {
        printf("update your TODO: ");
        fgets(buffer, MAX_STRING_SIZE, stdin);
        fputs(buffer, f_tmp);
      } else {
        fputs(buffer, f_tmp);
      }
    }
    fclose(f_read);
    fclose(f_tmp);
    remove(org_file_name);
    rename(tmp_file_name, org_file_name);
  }
}

void clearTodoList() {
  char file_name[] = "todo.txt";
  if (remove(file_name) == 0)
    printf("Todo list cleared\n");
  else
    printf("Error clearing the todo list\n");
}

int main() {
  char buffer[MAX_STRING_SIZE];
  // addTodo(buffer);
  printTodo(buffer);
  markTodoByLineNumber(buffer);
  updateTodoByLineNumber(buffer);

  return 0;
}
