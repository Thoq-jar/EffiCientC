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
 * along with EffiCientC. If not, see <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
 */

 #include "../Effic/effic.h"

 #define MAX_INPUT_LENGTH memBytes * 2
 const int memBytes = 100000;

 enum Commands {
     CMD_QUIT,
     CMD_MEMVIEW,
     CMD_HELP,
     CMD_UNKNOWN
 };

 volatile sig_atomic_t interrupted = 0;
 int *arr = NULL;

 void handle_sigint(int sig) {
     interrupted = 1;
     if (arr != NULL) {
         efree(arr);
         arr = NULL;
         if (arr == NULL) {
             println("\nMemory successfully freed!");
         } else {
             eFreeException();
         }
     }
     effic_exit(0);
 }

 enum Commands parse_command(const char *input) {
     if (estrcmp(input, "quit") == 0) {
         return CMD_QUIT;
     } else if (estrcmp(input, "memdump") == 0) {
         return CMD_MEMVIEW;
     } else if (estrcmp(input, "help") == 0) {
         return CMD_HELP;
     } else {
         return CMD_UNKNOWN;
     }
 }

 int main(int argc, char *argv[]) {
     char input[MAX_INPUT_LENGTH];
     bool memoryFreed = false;
     arr = (int *)emalloc(sizeof(int) * memBytes);
     if (arr == NULL) {
         arr = (int *)emalloc(sizeof(int) * memBytes);
     }
     for (int i = 0; i < memBytes; ++i) {
         arr[i] = i;
     }

     println("Memory successfully allocated!");
     print("\nInput string: ");
     for (int i = 1; i < argc; ++i) {
         println("%s", argv[i]);
     }

     println("Type something and press Enter (max %d characters): ", MAX_INPUT_LENGTH - 1);
     println("Type 'quit' or press CTRL+C to exit.");
     print("\n");
     signal(SIGINT, handle_sigint);
     while (!interrupted) {
         print("User input > ");
         effic_size_t bytes_read = egetln(input, sizeof(input));
         if (bytes_read > 0) {
             if (input[bytes_read - 1] == '\n') {
                 input[bytes_read - 1] = '\0';
             }
             print("EffiCientC I/O> ");

             enum Commands cmd = parse_command(input);

             switch (cmd) {
                 case CMD_QUIT:
                     println("Exiting...");
                     efree(arr);
                     memoryFreed = true;
                     if (!memoryFreed) {
                         eFreeException();
                     } else {
                         println("Memory successfully freed!");
                     }
                     println("Goodbye!");
                     effic_exit(0);
                     break;

                 case CMD_MEMVIEW:
                     println("Memory array:");
                     for (int i = 0; i < memBytes; ++i) {
                         print("%d ", arr[i]);
                     }
                     print("\n");
                     break;

                 case CMD_HELP:
                     println("Commands: ");
                     println("quit - Quits the program");
                     println("memview - Displays the memory array");
                     println("help - Displays this message");
                     break;

                 case CMD_UNKNOWN:
                 default:
                     println("You typed: %s", input);
                     break;
             }
         }
     }
     return 0;
 }
