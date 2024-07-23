/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * efficrand.c is the rand implementation for effic, thats it, nothing more nothing less lol
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

#define RAND_MAX 2147483647  // modulus
#define MULTIPLIER 48271     // multiplier

unsigned long seed = 1; // init seeds

int effic_rand(void) {
    bool memoryFreed = false;
    int *arr = (int *) emalloc(sizeof(int) * 10);
    static int counter = 0;
    const int resetInterval = 100;
    const int maxCounterValue = 10000;

    counter++;

    if (counter >= resetInterval) {
         counter = 0;
    }

    effic_time_t currentTime = time(NULL);
    int randomNumber = currentTime + counter % maxCounterValue;

    randomNumber %= 500;
    return randomNumber;
    efree(arr);
}
