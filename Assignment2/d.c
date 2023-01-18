#include<stdio.h>

int main(){
    
    int a, b, c, d;
    double sum;

    for(int i=0; i<3; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sum = a*2+b*2+c*2+d;
        printf("%.2lf\n", sum);   
    }

    return 0;
}