#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    if(pid == 0){
        printf("Child 1: %d %d\n",getpid(),getppid());
    }else if(pid > 0){
        printf("Parent: %d\n",getpid());
    }else{
        printf("Error\n");
        return EXIT_FAILURE;
    }
}