#include<stdio.h>

int main(){

    int a, m, f;
    double final;

    scanf("%d %d %d", &a, &m, &f);
    final = a * 0.2 + m * 0.3 + f * 0.5;

    printf("%.2lf\n", final);

    return 0;
}