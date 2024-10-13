/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * estrcmp.c is for string comparison
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

int estrcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2;
}