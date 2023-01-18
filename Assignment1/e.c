#include<stdio.h>

int main(){

    char nama1[101], nama2[101];
    double height1, height2;
    int age1, age2;

    scanf("%s %lf %d %s %lf %d", nama1, &height1, &age1, nama2, &height2, &age2);

    printf("Name 1: %s\n", nama1);
    printf("Height 1: %.2lf\n", height1);
    printf("Age 1: %d\n", age1);
    printf("Name 2: %s\n", nama2);
    printf("Height 2: %.2lf\n", height2);
    printf("Age 2: %d\n", age2);
    return 0;
}