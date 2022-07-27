#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

#define PROGRAM_PATH "./countdown"

extern char **environ;

int main(void) {



    // countdown from 5
    pid_t pid;

    char *spawn_argv[] = {PROGRAM_PATH, "5", NULL};


    if (posix_spawn(&pid, "./countdown", 
               NULL, NULL,
               spawn_argv, environ) != 0) {
        perror("posix_spawn");
        return 1;
    }


    int exit_status;

    if (waitpid(pid, &exit_status, 0) == -1) {
        perror("waitpid");
        return 1;
    }


    printf("hooray!\n");

    return 0;
}
