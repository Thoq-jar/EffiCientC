/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present Tristan
 *
 * exception.c handles exceptions in code
 *
 * EffiCientC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Thoq License for more details.
 *
 * You should have received a copy of the Thoq License
 * along with EffiCientC. If not, see <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
 */

#include "effic.h"

int genericException(void) {
    println("An unknown error occurred!");
    println("Please review the code or ask for assistance from the developer.");
    println("Fatal error reason: ");
    println("An error occurred!");
    return 2;
}

int eMallocException(void) {
    println("The code failed to allocate memory.");
    println("Please review the code or ask for assistance from the developer.");
    print("Reason: ");
    println("Failed to allocate memory.");
    return 1;
}

int eFreeException(void) {
    println("The code failed to free the allocated memory.");
    println("Please review the code or ask for assistance from the developer.");
    print("Reason: ");
    println("Failed to free memory.");
    return 1;
}
