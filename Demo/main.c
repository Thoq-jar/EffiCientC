/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present Tristan
 *
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

#define MAX_INPUT_LENGTH 1000

volatile sig_atomic_t interrupted = 0;
int *arr = NULL;

void handle_sigint(int sig) {
    interrupted = 1;
    if (arr != NULL) {
        efree(arr);
        arr = NULL;
    }
    println("\nMemory successfully freed!");
    exit(0);
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LENGTH];
    const int numInts = 1000;
    arr = (int *)emalloc(sizeof(int) * numInts);
    bool memoryFreed = false;

    if (arr == NULL) {
        eMallocException();
        return 1;
    }

    for (int i = 0; i < numInts; ++i) {
        arr[i] = i + 1;
    }

    const size_t totalSizeBytes = sizeof(int) * numInts;
    const double totalSizeMB = (double)totalSizeBytes / (1024.0 * 1024.0);

    println("Memory successfully allocated!");

    for (int i = 0; i < 10; ++i) {
        print("%d ", arr[i]);
    }
    print("\n");

    char sizeBuffer[20];
    esnprint(sizeBuffer, sizeof(sizeBuffer), "%.2f", totalSizeMB);
    print("Total size: %s MB\n", sizeBuffer);

    println("\nInput string:");
    for (int i = 1; i < argc; ++i) {
        println("%s", argv[i]);
    }

    println("Type something and press Enter (max %d characters): ", MAX_INPUT_LENGTH - 1);
    println("Type 'quit' to exit.");
    print("\n");
    signal(SIGINT, handle_sigint);
    while (!interrupted) {
        print("User input > ");
        ssize_t bytes_read = egetln(input, sizeof(input));
        if (bytes_read > 0) {
            if (input[bytes_read - 1] == '\n') {
                input[bytes_read - 1] = '\0';
            }
            print("EffiCientC I/O> ");
            switch (estrcmp(input, "quit")) {
            case 0:
                println("Exiting...");
                efree(arr);
                memoryFreed = true;
                if (!memoryFreed) {
                    eFreeException();
                } else {
                    println("Memory successfully freed!");
                }
                println("Goodbye!");
                return 0;
            default:
                print("You entered: ", 11);
                println(input, bytes_read);
                continue;
            }
        }
    }

    return 0;
}
