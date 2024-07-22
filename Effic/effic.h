/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * effic.h is the header file to tie it all together
 *
 * EffiCientC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Thoq License for more details.
 *
 * You should have received a copy of the Thoq License
 * along with EffiCientC. If not, see <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
*/

// hedder guard
#ifndef EFFIC_H
#define EFFIC_H

// imports
#include <signal.h> // it works
#include <sys/syscall.h> // i hope this isnt just a macOS thing
#include <unistd.h> // fuck windows

// constants
#define SIGINT  2
#define __need___va_list
#define __need_va_list
#define __need_va_arg
#define __need___va_copy
#define __need_va_copy

// macros
#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
    #pragma GCC system_header
#endif

// null def
#ifndef NULL
    #define NULL ((void *)0)
#endif

// size_t
#ifndef _Effic_SIZE_T_DEFINED
    #define _Effic_SIZE_T_DEFINED
    typedef unsigned long effic_size_t;
#endif

// off_t
#ifndef _Effic_OFF_T_DEFINED
    #define _Effic_OFF_T_DEFINED
    typedef long effic_off_t;
#endif

// effic_stdarg
#ifndef __STDARG_H
    #define __STDARG_H
#endif

// mode_t
#ifndef _Effic_MODE_T_DEFINED
    #define _Effic_MODE_T_DEFINED
    typedef unsigned int effic_mode_t;
#endif

// booleans
#if __has_include_next(<stdbool.h>)
    #include_next <stdbool.h>
#endif

// functions:
void effic_putchar(char c);
void effic_puts(const char *str);
size_t effic_strlen(const char *str);

// estdlib:
void effic_exit(int status);

// I/O functions:
void print(const char *format, ...);
void println(const char *format, ...);
int esnprint(char *str, size_t size, const char *format, ...);
effic_size_t egetln(char *buffer, size_t max_length);

// string functions:
int estrcmp(const char *s1, const char *s2);

// emalloc / mem functions:
void* emalloc(size_t size);
void efree(void* ptr);

// effic_unistd / stdlib:
void printHex(int val);
int effic_rand(void);
int effic_close(int fd);
int effic_open(const char *pathname, int flags, effic_mode_t mode);
int effic_execve(const char *pathname, char *const argv[], char *const envp[]);
effic_size_t effic_read(effic_size_t fd, void *buf, effic_size_t count);
effic_size_t effic_write(int fd, const void *buf, size_t count);
effic_off_t effic_lseek(int fd, effic_off_t offset, int whence);
pid_t effic_fork(void);
pid_t effic_getpid(void);
pid_t effic_wait(int *status);

// system functions:
int	syscall(int, ...);
void *sbrk(int);
int	siginterrupt(int, int);

// exceptions:
int genericException();
int eMallocException();
int eFreeException();

// arg definitions
#ifdef __need___va_list
    #include <__stdarg___gnuc_va_list.h>
    #undef __need___va_list
#endif

#ifdef __need_va_list
    #include <__stdarg_va_list.h>
    #undef __need_va_list
#endif

#ifdef __need_va_arg
    #include <__stdarg_va_arg.h>
    #undef __need_va_arg
#endif

#ifdef __need___va_copy
    #include <__stdarg___va_copy.h>
    #undef __need___va_copy
#endif

#ifdef __need_va_copy
    #include <__stdarg_va_copy.h>
    #undef __need_va_copy
#endif

#endif // EFFIC_H
