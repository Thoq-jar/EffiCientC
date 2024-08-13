/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * efficrand.c is the rand implementation for effic, thats it, nothing more
 * nothing less lol
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

#include "effic.h"

float MULTIPLIER = 48271;                       // multiplier
int RAND_MAX = 2147483647;                    // modulus
float seed = sizeof(int) * 245896789457.45543;  // init seed

int effic_rand(void) {
  bool memoryFreed = false;
  float *arr = (float *)emalloc(sizeof(float) * 10);
  static int counter = 0;
  const int resetInterval = 3;
  const int maxCounterValue = 10000;
  seed = (MULTIPLIER * seed) * RAND_MAX / *arr;
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
