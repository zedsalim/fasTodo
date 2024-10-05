# Fast Todo

| Demo 1 | Demo 2 | Demo 3 |
|-------|-------|-------|
| ![Demo 1](https://salimzaidi.site/media/images/uploads/81a3e9fa-13ed-4b21-bedb-f3b388e55d84.webp) | ![Demo 2](https://salimzaidi.site/media/images/uploads/53d748df-4448-4cb2-8bcb-bf843bf3cb3c.webp) | ![Demo 3](https://salimzaidi.site/media/images/uploads/f4e500bf-8960-4c4a-a1fb-d3217c73eb18.webp) |
| Demo 4 | Demo 5 | Demo 6 |
| ![Demo 4](https://salimzaidi.site/media/images/uploads/fffad6fb-ebc2-4f54-9079-5a06044edc33.webp) | ![Demo 5](https://salimzaidi.site/media/images/uploads/4bc9bc7b-222a-4b9b-83ba-0de564f2ef0e.webp) | ![Demo 6](https://salimzaidi.site/media/images/uploads/9afaecba-8425-4cb3-b5db-06704c6ac4b5.webp) |


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
