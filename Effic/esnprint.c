/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present Tristan
 *
 * esnprint.c is for printing formatted strings
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

int esnprint(char * str, size_t size,
  const char * format, ...) {
  va_list args;
  va_start(args, format);

  const char * arg = format;
  char * dest = str;
  int count = 0;
  size_t remaining = size > 0 ? size - 1 : 0;

  while ( * arg != '\0') {
    if ( * arg == '%' && * (arg + 1) != '\0') {
      switch ( * (arg + 1)) {
      case 'd': {
        int num = va_arg(args, int);
        char buffer[20];
        int length = 0;
        int is_negative = 0;

        if (num == 0) {
          * dest++ = '0';
          count++;
        } else {
          if (num < 0) {
            is_negative = 1;
            num = -num;
          }
          while (num != 0) {
            buffer[length++] = num % 10 + '0';
            num = num / 10;
          }
          if (is_negative) {
            * dest++ = '-';
            count++;
          }
          while (length > 0) {
            * dest++ = buffer[--length];
            count++;
            remaining--;
            if (remaining == 0) {
              break;
            }
          }
        }
        arg += 2;
        continue;
        break;
      }

      case 'f': {
        double num = va_arg(args, double);
        int int_part = (int) num;
        double decimal_part = num - int_part;
        char buffer[32];
        int length = 0;
        int int_length = 0;

        while (int_part != 0) {
          buffer[int_length++] = int_part % 10 + '0';
          int_part = int_part / 10;
        }
        while (int_length > 0) {
          * dest++ = buffer[--int_length];
          count++;
          remaining--;
          if (remaining == 0) {
            break;
          }
        }

        if (decimal_part != 0.0) {
          * dest++ = '.';
          count++;
          remaining--;

          while (length < 2) {
            decimal_part *= 10;
            int digit = (int) decimal_part;
            * dest++ = digit + '0';
            count++;
            remaining--;
            decimal_part -= digit;
            length++;
            if (remaining == 0) {
              break;
            }
          }
        }

        arg += 2;
        continue;
      }
      }
    }

    * dest++ = * arg++;
    count++;
    remaining--;
    if (remaining == 0) {
      break;
    }
  }

  va_end(args);
  * dest = '\0';

  return count;
}
