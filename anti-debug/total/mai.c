void tracee() {
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    raise(SIGCONT);//to make it actually stop


