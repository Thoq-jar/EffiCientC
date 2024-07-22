/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * efficrand.c is the rand implementation for effic, thats it, nothing more nothing less lol
 * TODO: Fix the fact that its always going to return the multiplier
 *
 * EffiCientC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Thoq License for more details.
 *
 * You should have received a copy of the Thoq License
 * along with EffiCientC. If not, see <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
*/

#define RAND_MAX 2147483647  // modulus
#define MULTIPLIER 16807     // multiplier

unsigned long seed = 1;  // initial seed

int effic_rand(void) {
    seed = (seed * MULTIPLIER) % RAND_MAX;
    return seed;
}

char randomChar(const char* str, int length) {
    int index = effic_rand() % length;
    return str[index];
}
