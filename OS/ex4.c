#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2, pid3, pid4;
    pid1 = fork();
    
    if (pid1 == 0) {
        printf("Child 1: %d %d\n", getpid(), getppid());
        exit(0);
    } 
    else if (pid1 > 0) {
        pid2 = fork();
        
        if (pid2 == 0) {
            printf("Child 2: %d %d\n", getpid(), getppid());
            pid3 = fork();
            
            if (pid3 == 0) {
                printf("Child 3: %d %d\n", getpid(), getppid());
                exit(0);
            } 
            else if (pid3 > 0) {
                wait(NULL);
                pid4 = fork();
                
                if (pid4 == 0) {
                    printf("Child 4: %d %d\n", getpid(), getppid());
                    exit(0);
                } 
                else if (pid4 > 0) {
                    wait(NULL);
                } else {
                    printf("Error in creating child 4\n");
                }
            } 
            else {
                printf("Error in creating child 3\n");
            }
        } 
        else if (pid2 > 0) {
            wait(NULL);
            printf("Parent: %d\n", getpid());
            wait(NULL);
            printf("Parent: Done\n");
        } 
        else {
            printf("Error in creating child 2\n");
        }
    } 
    else {
        printf("Error in creating child 1\n");
    }
    
    return 0;
}