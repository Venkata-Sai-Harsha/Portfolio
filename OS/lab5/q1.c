#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8;
    pid1 = fork();
    if(pid1 == 0){
        printf("Child B process. PID: %d PPID: %d\n", getpid(), getppid());
    }
    else if(pid1 > 0){
        pid2 = fork();
        if(pid2 == 0){
            printf("Child C process. PID: %d PPID: %d\n", getpid(), getppid());
            pid4 = fork();
            if(pid4 == 0){
                printf("Child E process. PID: %d PPID: %d\n", getpid(), getppid());
            }
            else if(pid4 > 0){
                pid5 = fork();
                if(pid5 == 0){
                    printf("Child F process. PID: %d PPID: %d\n", getpid(), getppid());
                }
                else if(pid5 > 0){
                    wait(NULL);
                }
                else{
                    printf("Error in creating child 5\n");
                }
            }
            else{
                printf("Error in creating child 4\n");
            }
        }
        else if(pid2 > 0){
            pid3 = fork();
            if(pid3 == 0){
                printf("Child D process. PID: %d PPID: %d\n", getpid(), getppid());
                pid6 = fork();
                if(pid6 == 0){
                    printf("Child G process. PID: %d PPID: %d\n", getpid(), getppid());
                    pid7 = fork();
                    if(pid7 == 0){
                        printf("Child H process. PID: %d PPID: %d\n", getpid(), getppid());
                    }
                    else if(pid7 > 0){
                        pid8 = fork();
                        if(pid8 == 0){
                            printf("Child I process. PID: %d PPID: %d\n", getpid(), getppid());
                        }
                        else if(pid8 > 0){
                            wait(NULL);
                        }
                        else{
                            printf("Error in creating child 8\n");
                        }
                    }
                    else{
                        printf("Error in creating child 7\n");
                    }
                }
                else if(pid6 > 0){
                    wait(NULL);
                }
                else{
                    printf("Error in creating child 6\n");
                }
            }
            else if(pid3 > 0){
                printf("Parent process. PID: %d\n", getpid());
                wait(NULL);
            }
            else{
                printf("Error in creating child 3\n");
            }
        }
        else{
            printf("Error in creating child 2\n");
        }
    }
    else{
        printf("Error in creating child 1\n");
    }

    return 0;
}