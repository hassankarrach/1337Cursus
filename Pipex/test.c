#include "./pipex.h"

int main() {
    int fd[2];
    int i = 0;
    int exit_status;


    while (i++ < 2)
    {
        int pid = fork();
        if (pid == 0) {
            if (i == 1)
            {
                printf("hello from child %d!\n", i);
                exit(99);
            }
            else if (i == 2)
            {
                printf("hello from child %d!\n", i);
                exit(5);
            }
        }
    }
    i = 0;
    while (i++ < 2)
    {
        wait(&exit_status);
        printf("on i = %d => %d\n", i, (exit_status >> 8) & 0xFF);
    }


    // printf("right before exit : %d\n", (exit_status >> 8) & 0xFF);
    exit ((exit_status >> 8) & 0xFF);
}
