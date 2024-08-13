/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * main.c is a demo file to demonstrate the uses of effic
 *
 * EffiCientC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Thoq License for more details.
 *
 * You should have received a copy of the Thoq License
 * along with EffiCientC. If not, see
 * <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
 */

// Add effic
#include "../Effic/effic.h"

// Constants
#define MAX_INPUT_LENGTH memBytes * 2
const int memBytes = 100000;

// Command macros
enum Commands { CMD_QUIT, CMD_MEMVIEW, CMD_HELP, CMD_UNKNOWN, CMD_RAND };

// Interrupt flag
volatile sig_atomic_t interrupted = 0;
// Memory array
int *arr = NULL;

void handle_sigint(int sig) {
  // Set interrupted flag
  interrupted = 1;
  // Check if memory was freed
  if (arr != NULL) {
    // Free memory
    efree(arr);
    if (arr == NULL) {
      // Memory was freed properly
      nline();
      println("Memory successfully freed!");
    } else {
      // Memory was not freed properly
      eFreeException();
    }
  }
  // Exit
  effic_exit(0);
}

// Strncmp function for commands
enum Commands parse_command(const char *input) {
  if (estrcmp(input, "quit") == 0) {
    return CMD_QUIT;
  } else if (estrcmp(input, "memdump") == 0) {
    return CMD_MEMVIEW;
  } else if (estrcmp(input, "help") == 0) {
    return CMD_HELP;
  } else if (estrcmp(input, "rand") == 0) {
    return CMD_RAND;
  } else {
    return CMD_UNKNOWN;
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Initialize variables
  char input[MAX_INPUT_LENGTH];
  bool memoryFreed = false;
  // Allocate memory
  arr = (int *)emalloc(sizeof(int) * memBytes);
  // Check if memory was allocated
  if (arr == NULL) {
    arr = (int *)emalloc(sizeof(int) * memBytes);
  }
  // Fill memory
  for (int i = 0; i < memBytes; ++i) {
    arr[i] = i;
  }

  // Print welcome message
  println("Memory successfully allocated!");
  // prints a newline (\n) character
  nline();
  print("Input string: ");
  for (int i = 1; i < argc; ++i) {
    println("%s", argv[i]);
  }
  // Print random number
  println("Random number: %d", effic_rand());
  println("Type something and press Enter (max %d characters): ",
          MAX_INPUT_LENGTH - 1);
  println("Type 'help'  for a list of comamnds.");
  nline();
  // Set signal handler
  signal(SIGINT, handle_sigint);
  // Main loop
  while (!interrupted) {
    print("User input > ");
    // Get user input
    effic_size_t bytes_read = egetln(input, sizeof(input));
    if (input[bytes_read - 1] == '\n') {
      input[bytes_read - 1] = '\0';
    }
    // Parse command
    enum Commands cmd = parse_command(input);
    // Switch command
    switch (cmd) {
    // Quit command
    case CMD_QUIT: {
      println("Exiting...");
      efree(arr);
      println("Goodbye!");
      effic_exit(0);
      break;
    // Example of memory
    case CMD_MEMVIEW:
      println("Memory array:");
      for (int i = 0; i < memBytes; ++i) {
        print("%d ", arr[i]);
      }
      nline();
      break;

    // help command
    case CMD_HELP:
      nline();
      println("Commands: ");
      println("quit - Quits the program - You can also use Ctrl+C to quit");
      println("memview - Displays the memory array");
      println("rand - Displays a random number");
      println("help - Displays this message");
      break;

    // Random number
    case CMD_RAND:
      println("Random number: %d", effic_rand());
      break;

    // Unknown command
    case CMD_UNKNOWN:
    default:
      println("EffiCientC I/O> You typed: %s", input);
      break;
    }
    }
  }
}
