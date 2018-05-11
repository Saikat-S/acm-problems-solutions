/***************************************************
 * Problem name : Paying Bills.cpp
 * Problem Link : https://toph.co/p/paying-bills
 * OJ           : Toph(IUT Contest)
 * Verdict      : AC
 * Date         : 2017-10-24
 * Problem Type : DP
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
#define MAX 33005
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
int coin[16], B[16];
int M;
vector<int>V[1005];
int dp[16][MAX];
void bitMask(int n) {
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                sum += coin[i];
            }
        }
        if (sum <= 1000) {
            V[sum].push_back(mask);
        }
    }
}
int Bill(int pos, int mask) {
    if (pos == M) {
        return __builtin_popcount(mask);
    }
    if (dp[pos][mask] != -1) return dp[pos][mask];
    int ans = 16;
    for (int i = 0; i < (int)V[B[pos]].size(); i++) {
        int need = V[B[pos]][i];
        if ((need & mask) != 0) continue;
        ans = min(ans, Bill(pos+1, (mask|need)));
        
        //~ ans = min(ans, Bill(pos + 1, need));
    }
    return dp[pos][mask] = ans;
}
int main () {
    int tc, N;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &coin[i]);
        }
        scanf("%d", &M);
        for (int i  = 0; i < M; i++) {
            scanf("%d", &B[i]);
        }
        bitMask(N);
        SET(dp);
        int ans = Bill(0, 0);
        if (ans == 16) {
            printf("Case %d: -1\n", t);
        } else {
            printf("Case %d: %d\n", t, ans);
        }
        for(int i = 0; i<1005; i++){
            V[i].clear();
            coin[i] = 0;
            B[i] = 0;
        }
    }
    return 0;
}

