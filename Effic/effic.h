/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present Tristan
 *
 *
 * EffiCientC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Thoq License for more details.
 *
 * You should have received a copy of the Thoq License
 * along with EffiCientC. If not, see <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
 */

// imports
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

// constants
#ifndef EFFIC_H
#define EFFIC_H

// macros
#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
    #pragma GCC system_header
#endif

// booleans
#if __has_include_next(<stdbool.h>)
    #include_next <stdbool.h>
#endif

// functions:
void effic_putchar(char c);
size_t effic_strlen(const char *str);
void effic_puts(const char *str);

// I/O functions:
void print(const char *format, ...);
void println(const char *format, ...);
int esnprint(char *str, size_t size, const char *format, ...);
ssize_t egetln(char *buffer, size_t max_length);

// string functions:
int estrcmp(const char *s1, const char *s2);

// emalloc / mem functions:
void* emalloc(size_t size);
void efree(void* ptr);

// exceptions:
int genericException();
int eMallocException();
int eFreeException();

#endif // EFFIC_H
