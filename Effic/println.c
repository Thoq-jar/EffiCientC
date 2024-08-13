/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * println.c is for printing newlines in effic
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

void println(const char *format, ...) {
  va_list args;
  va_start(args, format);

  const char *arg = format;
  while (*arg != '\0') {
    if (*arg == '%' && *(arg + 1) != '\0') {
      switch (*(arg + 1)) {
      case 's': {
        const char *str = va_arg(args, const char *);
        effic_puts(str);
        break;
      }
      case 'd': {
        int num = va_arg(args, int);
        char buffer[20];
        int length = 0;
        if (num == 0) {
          effic_putchar('0');
        } else {
          int is_negative = 0;
          if (num < 0) {
            is_negative = 1;
            num = -num;
          }
          while (num != 0) {
            buffer[length++] = num % 10 + '0';
            num = num / 10;
          }
          if (is_negative) {
            effic_putchar('-');
          }
          for (int i = length - 1; i >= 0; i--) {
            effic_putchar(buffer[i]);
          }
        }
        break;
      }
      default:
        effic_putchar(*arg);
        effic_putchar(*(arg + 1));
        break;
      }
      arg += 2;
    } else {
      effic_putchar(*arg);
      arg++;
    }
  }

  effic_putchar('\n');

  va_end(args);
}
