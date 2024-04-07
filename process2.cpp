#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <address>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    unsigned long address;
    sscanf(argv[2], "%lx", &address);

    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    waitpid(pid, NULL, 0);

    long data = ptrace(PTRACE_PEEKDATA, pid, (void *)address, NULL);
    printf("Read data from %p: %ld\n", (void *)address, data);

    ptrace(PTRACE_DETACH, pid, NULL, NULL);

    return 0;
}
