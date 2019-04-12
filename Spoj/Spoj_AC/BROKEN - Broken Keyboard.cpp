/***************************************************
 * Problem Name : BROKEN - Broken Keyboard.cpp
 * Problem Link : https://www.spoj.com/problems/BROKEN/en/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2019-02-07
 * Problem Type : two pointer
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
#define MAX 100000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd (ll a, ll b) {
    if (a % b == 0) return b;

    return gcd (b, a % b);
}
ll lcm (ll a, ll b) {
    return a * b / gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
map<char, int>mp;
int main () {
    int m;

    while (scanf ("%d", &m) == 1 && m != 0) {
        string ar;
        getchar();
        getline (cin, ar);
        int N = ar.size();
        int mx = 0, cnt = 0;

        for (int L = 0, R = 0; R < N; ) {
            mp[ar[R]]++;

            if (mp[ar[R]] == 1) cnt++;

            R++;

            while (cnt > m) {
                mp[ar[L]]--;

                if (mp[ar[L]] == 0) cnt--;

                L++;
            }

            int ans = R - L;
            mx = max (mx, ans);
        }

        printf ("%d\n", mx);
        mp.clear();
    }

    return 0;
}
