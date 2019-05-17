/***************************************************
 * Problem Name : B.cpp
 * Problem Link : https://codeforces.com/contest/1156/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-01
 * Problem Type : Edu - B
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
bool isValid (vector<char>ans) {
    for (int i = 1; i < (int) ans.size(); i++) {
        int a = ans[i - 1];
        int b = ans[i];

        if (abs (b - a) == 1) {
            return false;
        }
    }

    return true;
}

int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        string str;
        cin >> str;
        int n = (int) str.size();
        map<char, int>mp;

        for (int i = 0; i < n; i++) {
            mp[str[i]]++;
        }

        vector<char>od, ev;
        int i = 1;

        for (char ch = 'a'; ch <= 'z'; ch++, i++) {
            if (mp[ch] != 0) {
                if (i % 2 == 0) {
                    for (int j = 1; j <= mp[ch]; j++) {
                        ev.pb (ch);
                    }

                } else {
                    for (int j = 1; j <= mp[ch]; j++) {
                        od.pb (ch);
                    }
                }
            }
        }

        vector<char>ans;

        for (int i = 0; i < (int) od.size(); i++) {
            ans.pb (od[i]);
        }

        for (int i = 0; i < (int) ev.size(); i++) {
            ans.pb (ev[i]);
        }

        if (isValid (ans) ) {
            for (int i = 0; i < (int) ans.size(); i++) {
                cout << ans[i];
            }

            nl;

        } else {
            ans.clear();

            for (int i = 0; i < (int) ev.size(); i++) {
                ans.pb (ev[i]);
            }

            for (int i = 0; i < (int) od.size(); i++) {
                ans.pb (od[i]);
            }

            if (isValid (ans) ) {
                for (int i = 0; i < (int) ans.size(); i++) {
                    cout << ans[i];
                }

                nl;

            } else {
                cout << "No answer\n";
            }
        }
    }

    return 0;
}
