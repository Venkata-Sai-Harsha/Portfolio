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
    if(pid==0){
        close(fd[0]);
        char str[1024];
        printf("Enter the input string: ");
        scanf("%s",str);
        write(fd[1],str,strlen(str)+1);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        char buf[1024];
        read(fd[0],buf,1024);
        for (int i = 0; buf[i] != '\0'; i++) {
            buf[i] = toupper(buf[i]);
        }
        printf("The input string is:%s",buf);
        close(fd[0]);
    }
}