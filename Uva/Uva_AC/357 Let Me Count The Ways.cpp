/***************************************************
 * Problem name : 357 Let Me Count The Ways.cpp
 * Problem Link : https://uva.onlinejudge.org/external/3/357.pdf                       
 * OJ           : Uva                                 
 * Verdict      : AC                      
 * Date         : 09.06.2017                         
 * Problem Type : DP                               
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU                      
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
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 30005
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int coin[] = {1, 5,10, 25, 50};
ll dp[6][MAX],make;
ll coinChange(ll i, ll amount){
	if(i>=5){
		if(amount == 0) return 1;
		else return 0;
	}
	if(dp[i][amount] != -1) return dp[i][amount];
	ll rel1 = 0, rel2 = 0;
	if(amount - coin[i]>=0) rel1 = coinChange(i, amount - coin[i]);
	rel2 = coinChange(i + 1, amount);
	
	return dp[i][amount] = rel1 + rel2;
}
int main () {
	SET(dp);
    while(scanf("%lld", &make) == 1){
		ll ans = coinChange(0,make);
		if(ans == 1){
			printf("There is only 1 way to produce %lld cents change.\n",make);
		}
		else{
			printf("There are %lld ways to produce %lld cents change.\n", ans, make);
		}
	}
    return 0;
}

