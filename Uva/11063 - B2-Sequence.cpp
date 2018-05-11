/***************************************************
 * Problem name : 11063 - B2-Sequence.cpp
 * Problem Link : https://uva.onlinejudge.org/external/110/11063.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-29
 * Problem Type : AdHoc
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
#define MAX 1000
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
int main () {
    int n, ar[MAX], t = 1;
    while (scanf("%d", &n) == 1) {
        int chk = 0, f = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
            if (chk < ar[i]) {
                chk = ar[i];
            } else {
                f = 1;
            }
        }
        if (f == 1) {
            printf("Case #%d: It is not a B2-Sequence.\n", t++);
            nl;
            continue;
        }
        map<int, int>mp;
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                int x = ar[i] + ar[j];
                //~ printf("%d ", x);
                if (mp[x] != 0) {
                    flag = true;
                    break;
                } else {
                    mp[x] = 1;
                }
            }
        }
        if (!flag) printf("Case #%d: It is a B2-Sequence.\n", t++);
        else printf("Case #%d: It is not a B2-Sequence.\n", t++);
        nl;
        mp.clear();

    }
    return 0;
}
