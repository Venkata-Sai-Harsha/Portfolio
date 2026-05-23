#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void reverese(int num){
    int rev = 0;
    while(num != 0){
        rev = rev*10 + num%10;
        num = num/10;
    }
    printf("Reversed number : %d\n",rev);
}

int main(){
    int fd1[2],fd2[2];
    int pid1,pid2;
    pipe(fd1);
    pipe(fd2);
    int num;
    if(pipe(fd1)==-1 || pipe(fd2)==-1){
        printf("pipe failed");
        exit(1);
    }
    pid1 = fork();
    if(pid1 == -1){
        printf("fork failed");
        exit(2);
    }
    if(pid1==0){
        close(fd1[1]);
        read(fd1[0],&num,sizeof(num));
        close(fd1[0]);
        pid2 = fork();
        if(pid2 == -1){
            printf("fork failed");
            exit(2);
        }
        if(pid2 == 0){
            close(fd2[1]);
            read(fd2[0],&num,sizeof(num));
            reverese(num);
            close(fd2[0]);
        }
        else{
            close(fd2[0]);
            write(fd2[1],&num,sizeof(num));
            close(fd2[1]);
            wait(NULL);
            printf("Child 1 : Done\n");
        }
    }
    else{
        close(fd1[0]);
        printf("Enter a number : ");
        scanf("%d",&num);
        write(fd1[1],&num,sizeof(num));
        close(fd1[1]);
        wait(NULL);
        printf("Parent : Done\n");
    }
}