#include<stdio.h>

int main(){

    int a, b;

    for(int i = 0; i < 3; i++){
        scanf("%d", &a);
        getchar();getchar();getchar();
        scanf("%d", &b);
        getchar();getchar();
        printf("%d\n", a+b);
    }

    return 0;
}