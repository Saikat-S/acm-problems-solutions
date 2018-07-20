/***************************************************
 * Problem name : 10066 - The Twin Towers.cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 27-04-17
 * Problem Type : DP(LCS)
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
#define MAX 105
using namespace std;
typedef long long ll;
int A[MAX], B[MAX];
int dp[MAX][MAX];
int n1, n2;
int LCS(int i, int j) {
    if (i == n1 || j == n2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (A[i] == B[j]) return ans = 1 + LCS(i + 1, j + 1);
    else {
        int val1 = LCS(i + 1, j);
        int val2 = LCS(i, j + 1);
        ans = max(val1, val2);
    }
    return dp[i][j] = ans;
}
int main () {
	int t = 1;
    while (scanf("%d %d", &n1, &n2) == 2 && n1 != 0 && n2 != 0) {
        for (int i = 0; i < n1; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n2; i++) scanf("%d", &B[i]);
        SET(dp);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",t++, LCS(0, 0));
    }
    return 0;
}

