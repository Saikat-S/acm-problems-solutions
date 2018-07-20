#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,t,te;
    long long s,n,x,y;
    scanf("%d",&i);

    for(j=1;j<=i;j++)
    {
        scanf("%lld",&s);
        n=ceil(sqrt((double)(s)));

        if(n*n-s<n)
        {
            x=n,y=n*n-s+1;
        }

        else
        {
            x=-n*n+2*n+s-1,y=n;
        }

        if(n&1)
        {
            te=x;
            x=y;
            y=te;
        }

        printf("Case %d: %lld %lld\n",j,x,y);


    }

    return 0;
}
