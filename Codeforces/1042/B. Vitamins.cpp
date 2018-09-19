/***************************************************
 * Problem Name : B. Vitamins.cpp
 * Problem Link : https://codeforces.com/contest/1042/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-17
 * Problem Type : Div 2 - B
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
#define pii pair<int,string>
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
#define MAX 10000005
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
    int n;
    cin >> n;
    vector<pii>v2, v3;
    int a = 10000005, b = 10000005, c = 10000005;

    for (int i = 0; i < n; i++) {
        int x;
        string str;
        cin >> x >> str;

        if ( (int) str.size() == 1) {
            if (str[0] == 'A') a = min (a, x);
            else if (str[0] == 'B') b = min (b, x);
            else c = min (c, x);

        } else if ( (int) str.size() == 2) {
            v2.pb (pii (x, str) );

        } else {
            v3.pb (pii (x, str) );
        }
    }

    int mn = 10000005;

    if (a != 10000005 && b != 10000005 && c != 10000005) mn = a + b + c;

    sort (all (v2) );

    if ( (int) v3.size() >= 1) {
        sort (all (v3) );
        mn = min (mn, v3[0].first);
    }

    for (int i  = 0; i < (int) v2.size(); i++) {
        string s = v2[i].second;

        if (s == "AB" || s == "BA") {
            if (c != 10000005) {
                int x = c + v2[i].first;
                mn = min (mn, x);
            }

        } else if (s == "AC" || s == "CA") {
            if (b != 10000005) {
                int x = b + v2[i].first;
                mn = min (mn, x);
            }

        } else if (s == "BC" || s == "CB") {
            if (a != 10000005) {
                int x = a + v2[i].first;
                mn = min (mn, x);
            }
        }
    }

    if ( (int) v2.size() >= 2) {
        int tmp = v2[0].first;
        string ss = v2[0].second;
        int cc;

        if (ss == "AB" || ss == "BA") {
            cc = 3;

        } else if (ss == "AC" || ss == "CA") {
            cc = 2;

        } else if (ss == "BC" || ss == "CB") {
            cc = 1;
        }

        for (int i  = 1; i < (int) v2.size(); i++) {
            string s = v2[i].second;

            if (s == "AB" || s == "BA") {
                if (cc == 1 || cc == 2) {
                    cc = 0;
                    tmp += v2[i].first;
                    break;
                }

            } else if (s == "AC" || s == "CA") {
                if (cc == 1 || cc == 3) {
                    cc = 0;
                    tmp += v2[i].first;
                    break;
                }

            } else if (s == "BC" || s == "CB") {
                if (cc == 2 || cc == 3) {
                    cc = 0;
                    tmp += v2[i].first;
                    break;
                }
            }
        }

        if (cc == 0) mn = min (mn, tmp);
    }

    if (mn == 10000005) cout << "-1\n";
    else cout << mn << "\n";

    return 0;
}
