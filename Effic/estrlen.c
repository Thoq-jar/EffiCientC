/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present Tristan
 *
 * estrlen.c is to mesure the length of stirngs in effic
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

size_t effic_strlen(const char *str) {
    size_t len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}
