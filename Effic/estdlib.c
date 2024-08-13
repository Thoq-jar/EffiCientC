/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * estdlib.c is designed to implement the standard library
 * functions for effic like stdlib.h does but I need to do a lot of shit
 * NOTE: each function based on POSIX system calls
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

char buffers[10];
int current_fd = 0;

void effic_exit(int status);
void effic_exit(int status) {
  syscall(SYS_exit, status); // its depricated but i dont care //
}

int effic_open(const char *pathname, int flags, effic_mode_t mode) {
  return open(pathname, flags, mode);
}

effic_size_t effic_read(effic_size_t fd, void *buf, effic_size_t count) {
  return read(fd, buf, count);
}

effic_size_t effic_write(int fd, const void *buf, effic_size_t count) {
  return write(fd, buf, count);
}

int effic_close(int fd) { return close(fd); }

effic_off_t effic_lseek(int fd, effic_off_t offset, int whence) {
  return lseek(fd, offset, whence);
}

pid_t effic_fork(void) { return fork(); }

pid_t effic_getpid(void) { return getpid(); }

int effic_execve(const char *pathname, char *const argv[], char *const envp[]) {
  return execve(pathname, argv, envp);
}
