//Student ID: 0511330
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
    int studentId = 511330; 
	printf("helloworld : %ld\n", syscall(335));
	printf("echo : %ld\n", syscall(336, studentId));
    printf("returnIndividualValues : %ld\n", syscall(337, studentId, 2, 30));
   	printf("addition : %ld\n", syscall(338, studentId, 10, 35));
    printf("multiplication : %ld\n", syscall(339, studentId, 11, 35));
    printf("dataTypes : %ld\n", syscall(340, studentId));
    return 0;
}
