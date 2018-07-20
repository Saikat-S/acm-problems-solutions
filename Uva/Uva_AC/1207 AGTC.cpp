/***************************************************
 * Problem name : 1207 AGTC.cpp
 * Problem Link : https://uva.onlinejudge.org/external/12/1207.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-26
 * Problem Type : DP(LCS)
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
#define MAX 2000
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
int dp[MAX][MAX];
string A, B;
int Edit_Dist(int a, int b) {
    if (a == 0) return b;
    if(b == 0) return a;
    if(dp[a][b] != -1) return dp[a][b];
    if(A[a-1] == B[b -1]){
        return Edit_Dist(a - 1, b - 1);
    }
    int in = Edit_Dist(a, b -1) + 1;
    int rm = Edit_Dist(a-1, b) + 1;
    int rp = Edit_Dist(a - 1, b -1) + 1;
    
    return  dp[a][b] = min(in, min(rm, rp));
}
int main () {
    int a, b;
    while (scanf("%d", &a) == 1) {
        getchar();
        cin >> A;
        cin >> b;
        getchar();
        cin >> B;
        SET(dp);
        printf("%d\n", Edit_Dist(a, b));
    }

    return 0;
}

