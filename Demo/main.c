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
    /*
    println("Memory array:");
    for (int i = 0; i < memBytes; ++i) {
        print("%d ", arr[i]);
    }
    print("\n");
    */
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
        // Read a line from the user, fuck scanf dont you dare make a pull request for that
        effic_size_t bytes_read = egetln(input, sizeof(input));
        if (bytes_read > 0) {
            if (input[bytes_read - 1] == '\n') {
                input[bytes_read - 1] = '\0';
            }
            print("EffiCientC I/O> ");
            if (!estrcmp(input, "quit")) {
                println("Exiting...");
                efree(arr);
                memoryFreed = true;
                if (!memoryFreed) {
                    eFreeException(); // death
                } else {
                    println("Memory successfully freed!");
                }
                println("Goodbye!");
                effic_exit(0);
            } else {
                println("You typed: %s", input);
            }
        }
    }
    return 0;
}
