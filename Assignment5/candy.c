#include<stdio.h>

int main()
{
    long long t,n,m,harga,term;

    scanf("%lld",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&m);
        term = 1000001;

        for(int j=0;j<n;j++)
        {
            scanf("%lld",&harga);
            if(harga<term)
                term = harga;
        }
        printf("Case #%d: %lld\n",i,m/term);
    }
    return 0;
}