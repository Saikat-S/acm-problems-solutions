/***************************************************
 * Problem Name : 11572 - Unique Snowflakes.cpp
 * Problem Link : https://uva.onlinejudge.org/external/115/11572.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-17
 * Problem Type : AdHoc
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define pb push_back
#define MAX 100005
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int tc;
    int n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        int cnt = 0, mx = 0;
        map<int, int>mp, pos;
        int ii = 0;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            if (mp[x] == 0) {
                if (pos[x] >= ii) {
                    mx = max (cnt, mx);
                    cnt = i - pos[x];
                    ii = pos[x] + 1;

                } else cnt++;

                mp[x] = 1;
                pos[x] = i;

            } else {
                mx = max (cnt, mx);
                cnt = i - pos[x];
                ii = pos[x] + 1;
                mp.clear();
                mp[x] = 1;
                pos[x] = i;
            }
        }

        mx = max (mx, cnt);
        cout << mx << "\n";
    }

    return 0;
}

