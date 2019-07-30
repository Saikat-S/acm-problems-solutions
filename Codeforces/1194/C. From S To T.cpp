/***************************************************
 * Problem Name : C. From S To T.cpp
 * Problem Link : https://codeforces.com/contest/1194/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-14
 * Problem Type : Edu R - C
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
#include<iomanip>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 105
#define INF 1000000000
#define MOD 1000000007
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
    int q;
    cin >> q;

    while (q--) {
        string s, t, p;
        cin >> s >> t >> p;
        map<char, int>mp;

        for (int i = 0; i < (int) p.size(); i++) {
            mp[p[i]]++;
        }

        bool f = false;
        bool vis[MAX];
        SET (vis, false);

        for (int i = 0, j = 0;;) {
            if (s[i] == t[j]) {
                vis[j] = true;
                i++, j++;

            } else {
                j++;
            }

            if (i == (int) s.size() ) {
                f = true;
                break;
            }

            if (j == (int) t.size() ) {
                break;
            }
        }

        if (!f) {
            cout << "NO\n";

        } else {
            f = false;

            for (int i = 0; i < (int) t.size(); i++) {
                if (!vis[i]) {
                    char ch = t[i];

                    if (mp[ch] > 0) {
                        mp[ch]--;
                    } else {
                        f = true;
                        break;
                    }
                }
            }

            if (!f) {
                cout << "YES\n";

            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
