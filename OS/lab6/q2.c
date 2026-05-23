#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int fd[2];
    int pid;
    pipe(fd);
    if(pipe(fd)==-1){
        printf("pipe failed");
        exit(1);
    }
    pid=fork();
    if(pid<0){
        printf("fork failed");
        exit(2);
    }
    int num;
    int sum = 0;
    if(pid==0){
        close(fd[1]);
        while((read(fd[0], &num, sizeof(num)))>0){
            sum = sum + num;
        }
        printf("child Process : %d\n",sum);
        close(fd[0]);
    }
    else{
        close(fd[0]);
        printf("Parent Process : \n");
        while(1){
            printf("Enter a number : ");
            if(scanf("%d", &num) != 1){
                break;
            }
            write(fd[1], &num, sizeof(num));
        }
        close(fd[1]);
    }
}