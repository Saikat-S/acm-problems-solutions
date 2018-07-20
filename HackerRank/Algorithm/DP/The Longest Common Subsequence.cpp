/***************************************************
 * Problem name : The Longest Common Subsequence.cpp
 * Problem Link : https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
 * OJ           : HackerRank
 * Verdict      : AC
 * Date         : 2017-11-09
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
#define MAX 105
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
int n, m;
int A[MAX], B[MAX], dp[MAX][MAX];
vector<int>V;
int LCS(int i, int j) {
    if (i == n || j == m) {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (A[i] == B[j]) {
        ans  = 1 + LCS(i + 1, j + 1);
    } else {
        int val1 = LCS(i + 1, j);
        int val2 = LCS(i, j + 1);
        ans  = max(val1, val2);
    }
    return dp[i][j] = ans;
}
void printLCS(int i, int j) {
    if (i == n || j == m) {
        for (int i = 0; i < (int)V.size(); i++) {
            if (i != 0) sp;
            printf("%d", V[i]);
        }
        return ;
    }
    if (A[i] == B[j]) {
        V.push_back(A[i]);
        printLCS(i + 1, j + 1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1, j);
        else printLCS(i, j+1);
    }
}
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    SET(dp, -1);
    LCS(0, 0);
    printLCS(0, 0);
    V.clear();
    return 0;
}
