/***************************************************
 * Problem name : 674 - Coin Change.cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 19-04-17
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
#define MAX 100
using namespace std;
typedef long long ll;
int coin[] = {50, 25, 10, 5, 1};
int make; 
int dp[5][7490];
int call(int i, int amount) {
    if (i >= 5) {
        if (amount == 0) return 1;
        else return 0;
    }
    if (dp[i][amount] != -1) return dp[i][amount];
    int ret1 = 0, ret2 = 0;
    if (amount - coin[i] >= 0) ret1 = call(i, amount - coin[i]);
    ret2 = call(i + 1, amount);
    //~ return dp[i][amount] = ret1 | ret2; ///check make or not...
    return dp[i][amount] = ret1 + ret2; ///check how many away...
}
int main () {
    memset(dp, -1, sizeof(dp));
    while (scanf("%d", &make) == 1) {
        printf("%d\n", call(0,make));
    }
    return 0;
}

