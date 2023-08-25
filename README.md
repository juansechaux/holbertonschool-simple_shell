# Simple Shell

This is a simple Unix shell program implemented in C, which allows users to interact with the system by executing commands. It provides a basic command-line interface that supports running commands, searching for executable files in the system's PATH, and displaying environment variables.

## Flowchart

![Flowchart](https://github.com/juansechaux/holbertonschool-simple_shell/blob/master/flowchartsSimple-Shell.png)

## Features

- Command execution: Run various system commands by entering them in the shell.
- PATH search: The shell searches for executable files in directories specified by the PATH environment variable.
- Built-in commands: Support for built-in commands like `exit` to exit the shell and `env` to display environment variables.
- Interactive prompt: Provides a prompt that indicates the user's input is expected.
- Background processes: Executes commands in the background using the '&' symbol.
- Handling whitespace: Handles leading/trailing whitespace and consecutive spaces in command input.

## Code Components

The code of the shell is divided into several key components:

1. **Header File (main.h):** Contains necessary includes and declarations used throughout the program. It also includes the external declaration of the `environ` variable to access environment variables.

2. **Command Path Search (`findpath` function):** This function takes an executable command as an argument and searches for its full path in the directories specified by the PATH environment variable.

3. **Command Execution (`checkcommand` function):** This function is responsible for executing a given command. It forks a child process, parses the command-line input, searches for the command in the PATH (if needed), and executes it using the `execve` system call.

4. **Main Function (`main` function):** The main function sets up the interactive loop of the shell. It displays a prompt, reads user input, processes commands (including built-in commands), and handles the execution of external commands.

## How to Use

If there are no arguments and the shell standard input is connected to a terminal, the shell is considered an interactive shell.

Interactive shells typically prompt before each command and handle programming and command errors differently.

- Compile the code using a C compiler:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -o simple_shell simple_shell.c

### Interactive Mode

Interactive Mode is the standard way of interacting with the program where the user provides input in real-time. In this mode, the program waits for user input, processes it, and responds immediately, creating a dynamic and iterative interaction.

1.  Run the compiled executable:
    
    `./simple_shell` 
    
2.  Once the shell is running, you can enter commands like in a typical Unix shell (ls, pwd, etc). You can execute system commands, use built-in commands like `exit`, and display environment variables using the `env` command.
    
3.  To exit the shell, simply enter the command:
    
    `exit` 

#### Examples Interactive Mode

    #cisfun$ ./simple_shell
    #cisfun$ /bin/pwd
    Output: /home/holbertonschool-simple_shell/simple_shell

    #cisfun$ ./simple_shell
    #cisfun$ pwd
    Output: /home/holbertonschool-simple_shell/simple_shell

#### Other uses of interactive mode

1.  Running system commands:
    
    `#cisfun$ ls -l` 
    
2.  Using built-in commands:

    `#cisfun$ env` 
    
3.  Exiting the shell:

    `#cisfun$ exit` 
    

### Non-Interactive Mode

Non-Interactive Mode, is a way of running the program without requiring direct input from the user in real-time. In this mode, the program takes input from a predefined source (such as a file or command line arguments) rather than interacting with the user via prompts or a terminal.

#### Examples Non-Interactive Mode

```
 $ echo "/bin/pwd" | ./simple_shell
 Output: /home/holbertonschool-simple_shell/simple_shell

 $ echo "pwd" | ./simple_shell
 Output: /home/holbertonschool-simple_shell/simple_shell
```

## Notes

-   This simple shell is intended for educational purposes and may not have the full feature set of a production-ready shell.
-   Built and tested on Unix-like systems.

## Author

This shell was implemented by Juan Sebastian Varcarcel Chaux and Gilberto Lozano. 
