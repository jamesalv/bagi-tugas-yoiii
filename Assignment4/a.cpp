#include <stdio.h>

int main(){

    long long t, a, b;
    double rotation;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        rotation = a*b/360.0;
        printf("%.2lf\n", rotation);
    }

    return 0;
}