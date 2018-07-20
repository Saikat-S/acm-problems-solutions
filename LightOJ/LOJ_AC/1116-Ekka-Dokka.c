#include<stdio.h>
int main()
{
    int tc,i;
    long long W,N,M;

    scanf("%d",&tc);

    for(i=1;i<=tc;i++)
    {
      scanf("%lld",&W);

      if(W%2!=0)
      {
          printf("Case %d: Impossible\n",i);
          continue;
      }

      N=W/2;
      M=2;

      while(N%2==0)
      {
          N = N/2;
          M=M*2;
      }
      printf("Case %d: %lld %lld\n",i,N,M);
    }

    return 0;
}
