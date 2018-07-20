/***************************************************
 * Problem name : 1145 - Dice (I) .cpp
 * Problem Link : http://www.lightoj.com/volume_showproblem.php?problem=1145
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-11-11
 * Problem Type : DP(iterator)
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
#define MAX 15005
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
//~ ll ar[5][MAX];
ll ar[MAX], arr[MAX];
int main () {
    ll tc, N, K, S;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld %lld", &N, &K, &S);
        SET(ar, 0);
        SET(arr, 0);
        arr[0] = 1;
        for (int i = 1; i <= N; i++) {
            for(int j = 0; j<i; j++) ar[j] = 0;
            //~ printf("%d:\n", i);
            for (int j = i; j <= S; j++) {
                if (j <= K) {
                    ar[j] = (ar[j - 1] + arr[j - 1]) % 100000007;
                    //~ ar[i][j] = (ar[i][j - 1] + ar[i - 1][j - 1]) % 100000007;
                    //~ printf("%d : %lld  = %lld + %lld\n",j, ar[j], ar[j-1], arr[j-1]);
                } else {
                    ar[j] = ((ar[j - 1] + arr[j - 1]) - arr[j - K - 1]) % 100000007;
                    //~ ar[i][j] = ((ar[i][j - 1] + ar[i - 1][j - 1]) - ar[i - 1][j - K - 1]) % 100000007;
                    if (ar[j] < 0) {
                        ar[j] += 100000007;
                    }
                    //~ printf("%d : %lld  = %lld + %lld\n",j, ar[j], ar[j-1], arr[j-1]);
                }
            }
            for(int j = 0; j<i; j++) {
                arr[j] = 0;
            }
            for(int j = i; j<=S; j++){
                arr[j] = ar[j];
            }
            //~ nl;
        }
        printf("Case %d: %lld\n", t, ar[S]);
    }
    return 0;
}
