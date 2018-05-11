#include<stdio.h>
#define MAX 10005
typedef long long ll;
ll dp[MAX];
ll a,b,c,d,e,f;
ll rec(ll n) {
    if(n == 0) return a;
    if(n == 1) return b;
    if(n == 2) return c;
    if(n == 3) return d;
    if(n == 4) return e;
    if(n == 5) return f;
    if(dp[n] != -1) return dp[n];
    else {
        dp[n] = (rec(n - 1) + rec(n - 2) + rec(n - 3) + rec(n - 4) + rec(n - 5) + rec(n - 6))%10000007;
        return dp[n];
    }
}
int main()
{
    ll n,tc,i,j;

    scanf("%lld", &tc);
    for(i = 1; i<=tc; i++) {
        for(j = 0; j<MAX; j++) {
            dp[j] = -1;
        }
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        printf("Case %lld: %lld\n",i, rec(n)%10000007);

    }
    return 0;
}
