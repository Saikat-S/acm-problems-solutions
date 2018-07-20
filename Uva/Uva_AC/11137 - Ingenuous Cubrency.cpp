/***************************************************
 * Problem name : 11137 - Ingenuous Cubrency.cpp
 * Problem Link : https://uva.onlinejudge.org/external/111/11137.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 13.05.2017                         
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
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define debug printf("#########\n")
#define nl printf("\n")
#define MAX 100000
using namespace std;
typedef long long ll;
int coin[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
ll make;
ll dp[22][10002];
ll call(ll i, ll amount) {
    if (i >= 21) {
        if (amount == 0) return 1;
        else return 0;
    }
    if (dp[i][amount] != -1) return dp[i][amount];
    ll ret1 = 0, ret2 = 0;
    if (amount - coin[i] >= 0) ret1 = call(i, amount - coin[i]);
    ret2 = call(i + 1, amount);
    //~ return dp[i][amount] = ret1 | ret2; ///check make or not...
    return dp[i][amount] = ret1 + ret2; ///check how many away...
}
int main () {
    memset(dp, -1, sizeof(dp));
    while (scanf("%lld", &make) == 1) {
        printf("%lld\n", call(0, make));
    }
    return 0;
}

