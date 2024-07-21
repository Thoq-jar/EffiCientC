/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present Tristan
 *
 * egetln.c is an input handler for effic
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

 effic_size_t egetln(char *buffer, size_t max_length) {
     size_t i = 0;
     char ch;

     while (i < max_length - 1) {
         if (read(STDIN_FILENO, &ch, 1) < 1) {
             break;
         }
         buffer[i++] = ch;
         if (ch == '\n') {
             break;
         }
     }

     buffer[i] = '\0';

     return i;
 }
