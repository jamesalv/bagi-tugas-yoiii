#include<stdio.h>

int main()
{
    long long a,b,c,t,cash;

    scanf("%lld",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        cash=(a/100)*b;
        if(cash>c)
            printf("Case #%d: %lld\n",i,c);
        else
            printf("Case #%d: %lld\n",i,cash);
    }

    return 0;
}