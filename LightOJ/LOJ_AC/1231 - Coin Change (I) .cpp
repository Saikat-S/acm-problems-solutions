/*************************************************** 
 * ███████╗ █████╗ ██╗██╗  ██╗ █████╗ ████████╗
 * ██╔════╝██╔══██╗██║██║ ██╔╝██╔══██╗╚══██╔══╝
 * ███████╗███████║██║█████╔╝ ███████║   ██║
 * ╚════██║██╔══██║██║██╔═██╗ ██╔══██║   ██║
 * ███████║██║  ██║██║██║  ██╗██║  ██║   ██║
 * ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝
 * Problem name : 1231 - Coin Change - I .cpp
 * OJ           : LOJ
 * Result       : AC
 * Date         : 20-04-17
 * Problem Type : DP
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define pii pair<int,int>
#define MAX 1000
using namespace std;
typedef long long ll;
ll coin[MAX], C[MAX], n,K;
ll dp[51][21][1005];
ll coin_change(ll i, ll amount,int taken) {
    if (i >= n) {
        if (amount == K) return 1;
        else return 0;
    }
    if (dp[i][taken][amount] != -1) return dp[i][taken][amount];
    int result1 = 0, result2 = 0;
    if((amount + coin[i]<=K) && taken<=C[i]){
		result1 = coin_change(i,amount+coin[i], taken+1);
	}
	result2 = coin_change(i+1,amount,1);
    
    return dp[i][taken][amount] = (result1 + result2)%100000007;
}
int main () {
    ll tc;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &n, &K);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &coin[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &C[i]);
        }
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %lld\n",t,coin_change(0,0,1)%100000007);
        //~ printf("Case %d: %lld\n", t, coin_change(0, K, 0));
    }
    return 0;
}

