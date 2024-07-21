#include "effic.h"

char buffers[10];
int current_fd = 0;

void effic_exit(int status);
void effic_exit(int status) {
    syscall(SYS_exit, status);
}

int effic_open(const char *pathname, int flags, effic_mode_t mode) {
    // TODO: Implement
    return 0;
}

effic_size_t effic_read(effic_size_t fd, void *buf, effic_size_t count) {
    if (fd >= sizeof(buffers)/sizeof(char)) {
        return -1;
    }

    char *dest = (char *)buf;
    effic_size_t bytesRead = 0;

    while (bytesRead < count && bytesRead < sizeof(buffers) - fd) {
        dest[bytesRead] = buffers[fd + bytesRead];
        bytesRead++;
    }

    return bytesRead;
}

effic_size_t effic_write(int fd, const void *buf, effic_size_t count) {
    // TODO: Implement
    return 0;
}

int effic_close(int fd) {
    // TODO: Implement
    return 0;
}

effic_off_t effic_lseek(int fd, effic_off_t offset, int whence) {
    // TODO: Implement
    return 0;
}

pid_t effic_fork(void) {
    // TODO: Implement
    return 0;
}

pid_t effic_getpid(void) {
    // TODO: Implement
    return 0;
}

pid_t effic_wait(int *status) {
    // TODO: Implement
    return 0;
}

int effic_execve(const char *pathname, char *const argv[], char *const envp[]) {
    // TODO: Implement
    return 0;
}
