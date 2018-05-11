/***************************************************
 * Problem name : 1119 - Pimp My Ride.cpp
 * Problem Link : http://www.lightoj.com/volume_showproblem.php?problem=1119                       
 * OJ           : LOJ                                  
 * Verdict      : AC                      
 * Date         : 2017-11-29                         
 * Problem Type : BitMaskDP                               
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU                     
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 16
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
ll cost[MAX][MAX];
ll dp[1<<MAX], n;
bool Check(ll N, ll pos){
    return (bool)(N & (1 << pos));
}
ll Set(ll N, ll pos){
    return N = (N | (1<<pos));
}
ll BitMask(ll mask){
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    ll mn = 1 << 28;
    for(int  i = 0; i<n; i++){
        if(Check(mask, i) == 0){
            ll price = cost[i][i];
            for(int j = 0; j<n; j++){
                if(i != j && Check(mask, j) == 1){
                    price += cost[i][j];
                }
            }
            ll ans = price + BitMask(Set(mask, i));
            mn = min(mn, ans);
        }
    }
    return dp[mask] = mn;
}
int main () {
    int tc;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
        scanf("%lld", &n);
        SET(dp, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                scanf("%lld", &cost[i][j]);
            }
        }
        printf("Case %d: %lld\n", t, BitMask(0));
    }
    return 0;
}
