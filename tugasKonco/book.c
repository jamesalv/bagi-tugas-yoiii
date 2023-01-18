#include<stdio.h>

int main()
{
    long long t,n,x,hald,halb,tot;

    scanf("%d",&t);
    tot=100000000;

    for(int i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&x);
        hald=(x-1)/2+(x-1)%2;

        if(n%2==0)
            halb=(n-x)/2+(n-x)%2;
        else
            halb=(n-x)/2;
        
        if(hald<tot)
            tot=hald;
        if(halb<tot)
            tot=halb;
        
        printf("Case #%d: %lld\n",i,tot);
    }

    return 0;
}