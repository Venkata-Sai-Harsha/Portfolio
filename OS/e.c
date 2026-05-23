#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 1024
#include <string.h>

int main(){


    /*fork();
    fork();
    printf("1");
    fork();
    printf("2");*/
    /*if(fork() || fork()){
        fork();
    }
    printf("3");*/
    /*int count = 0;
    for (int i=0;i<3;i++){
        fork();
        count++;
    }
    printf("count:%d\n",count);*/

    /*int pfd[2];
    int nread;
    int pid;
    char buf[SIZE];
    if(pipe(pfd) == -1){
        perror("pipe failed");
        exit(1);
    }
    if((pid=fork()) < 0){
        perror("pipe failed");
        exit(2);
    }
    if(pid==0){
        close(pfd[1]);
        while((nread=read(pfd[0],buf,SIZE))!=0){
            printf("child read %s\n",buf);
        }
        close(pfd[0]);
    }
    else{
        close(pfd[0]);
        strcpy(buf,"hello...");
        write(pfd[1],buf,strlen(buf)+1);
        close(pfd[1]);
    }*/

    /*int fd[2];
    pipe(fd);

    // Parent process writes data to the pipe.
    write(fd[1], "Hello, world!", 12);

    // Child process reads data from the pipe.
    char buffer[12];
    read(fd[0], buffer, 12);

    printf("The child process read: %s\n", buffer);*/
    int x=10;
    fork();
    if(fork()&&fork()||fork()){
        x++;
    }
    printf("%d\n",x);

    return 0;
}