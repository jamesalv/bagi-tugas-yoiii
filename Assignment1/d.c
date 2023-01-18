#include<stdio.h>

int main(){
    char N[101], A[9];
    int age;

    gets(N);
    scanf("%s %d", A, &age);
    
    printf("Name: %s\nNIS: %s\nAge: %d\n", N, A, age);
    return 0;
}