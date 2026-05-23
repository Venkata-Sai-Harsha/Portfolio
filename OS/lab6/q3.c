#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 256
int main() {
    int pipefd1[2]; // Parent to Child #1
    int pipefd2[2]; // Parent to Child #2
    int pipefd3[2]; // Child #1 to Parent
    int pipefd4[2]; // Child #2 to Parent
    pid_t pid1, pid2;
    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1 || pipe(pipefd3) == -1 || pipe(pipefd4) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {
    // Child process #1
        close(pipefd1[1]);
        close(pipefd2[0]);
        close(pipefd2[1]);
        close(pipefd3[0]);
        close(pipefd4[0]);
        int num, sum = 0;
        while (read(pipefd1[0], &num, sizeof(int)) > 0) {
            sum += num;
        }
        close(pipefd1[0]);
        write(pipefd3[1], &sum, sizeof(int));
        close(pipefd3[1]);
        exit(EXIT_SUCCESS);
    }
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
    // Child process #2
        close(pipefd1[0]);
        close(pipefd1[1]);
        close(pipefd2[1]);
        close(pipefd3[0]);
        close(pipefd3[1]);
        close(pipefd4[0]);
        int num, count = 0;
        while (read(pipefd2[0], &num, sizeof(int)) > 0) {
            count++;
        }
        close(pipefd2[0]);
        write(pipefd4[1], &count, sizeof(int));
        close(pipefd4[1]);
        exit(EXIT_SUCCESS);
    }
    else {
        // Parent process
        close(pipefd1[0]);
        close(pipefd2[0]);
        close(pipefd3[1]);
        close(pipefd4[1]);
        int num, sum = 0, count = 0;
        while (1) {
            printf("Enter an integer (or a special character to stop): ");
            if (scanf("%d", &num) != 1) {
                break;
            }
            int square = num * num;
            write(pipefd1[1], &square, sizeof(int));
            write(pipefd2[1], &square, sizeof(int));
            sum += square;
            count++;
        }
        close(pipefd1[1]);
        close(pipefd2[1]);
        int child1_sum, child2_count;
        double average;
        read(pipefd3[0], &child1_sum, sizeof(int));
        read(pipefd4[0], &child2_count, sizeof(int));
        close(pipefd3[0]);
        close(pipefd4[0]);
        if (child2_count != 0) {
            average = (double)child1_sum / child2_count;
            printf("Mean of the squares: %.2lf\n", average);
        } else {
            printf("No numbers were entered.\n");
        }
        exit(0);
    }
}