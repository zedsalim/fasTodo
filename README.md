# Fast Todo

Fast Todo is a simple command-line TODO list manager written in C. This program allows users to add, view, update, mark as finished, and clear tasks from their TODO list efficiently.

## Features

- **Add a new todo**: Quickly add a new task to your list.
- **Print all todos**: View all your current tasks with line numbers.
- **Mark a todo as finished**: Easily mark a task as completed by specifying its line number.
- **Update a todo**: Modify existing tasks in your list.
- **Clear the todo list**: Remove all tasks at once.
- **Help command**: Access usage instructions and options.

### Options:

- `-a`: Add a new todo
- `-p`: Print all todos
- `-m`: Mark a todo as finished
- `-u`: Update a todo
- `-c`: Clear the todo list
- `-h`: Display help information

## Installation & Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/zedsalim/fasTodo.git
   cd fasTodo
   ```

2. Compile the program:
   ```bash
   gcc main.c -o fasTodo
   ```

3. Run the program:
   ```bash
   ./fasTodo -[OPTION]
   ```

## File Storage

Todos are stored in a plain text file named `todo.txt` in the same directory as the program. The program checks for the existence of this file and handles file operations such as reading and writing tasks.
