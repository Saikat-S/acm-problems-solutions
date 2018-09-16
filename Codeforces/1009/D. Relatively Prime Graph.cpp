/***************************************************
 * Problem Name : D. Relatively Prime Graph.cpp
 * Problem Link : http://codeforces.com/contest/1009/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-22
 * Problem Type : Educational round - D
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
    int n, m;
    cin >> n >> m;
    vector<pii>v;

    if (m < (n - 1) ) {
        cout << "Impossible\n";
        return 0;
    }

    int flag = 0, cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (__gcd (i, j) == 1) {
                cnt++;
                v.pb (pii (i, j) );

                if (cnt == m) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag) break;
    }

    if (flag) {
        cout << "Possible\n";

        for (int i = 0; i < (int) v.size(); i++) {
            cout << v[i].first << " " << v[i].second << "\n";
        }

    } else {
        cout << "Impossible\n";
    }

    return 0;
}
