/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * effictohex.c is broken ;)
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

void printHex(int val) {
    char hex_val[33];
    int idx = 0;
    do {
        int rem = val % 16;
        if (rem < 10) {
            hex_val[idx++] = '0' + rem;
        } else {
            hex_val[idx++] = 'A' + rem - 10;
        }
        val /= 16;
    } while (val > 0);

    hex_val[idx] = '\0';

    print("0x");

    for (int j = 0; j < idx; ++j) {
        print("%d ", hex_val[j]);
    }
}
