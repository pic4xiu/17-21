
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/user.h>

#define SYS_CUSTOM_write 10000
