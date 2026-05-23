#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2;
    pid1 = fork();

    if (pid1 == 0) {
        printf("Child 1: %d %d\n", getpid(), getppid());
        pid2 = fork();

        if (pid2 == 0) {
            printf("Child 2: %d %d\n", getpid(), getppid());
        } else if (pid2 > 0) {
            wait(NULL);
        } else {
            printf("Error creating child 2\n");
        }
    } 
    else if (pid1 > 0) {
        printf("Parent: %d\n", getpid());
        wait(NULL);
        printf("Parent: Done\n");
    } 
    else {
        printf("Error creating child 1\n");
    }

    return 0;
}