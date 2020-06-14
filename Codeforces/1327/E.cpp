/***************************************************
 * Problem Name : E.cpp
 * Problem Link : https://codeforces.com/contest/1327/problem/E
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-04-30
 * Problem Type : Div/Edu -
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <set>
#include <cassert>
#include <iomanip>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin)
#define __FileWrite freopen ("output.txt", "w", stdout)
#define SET(a,v) memset(a,v,sizeof(a))
#define SZ(v) (int)v.size()
#define pii pair<int,int>
#define pil pair <int, ll>
#define pli pair <ll, int>
#define pll pair <ll, ll>
#define debug cout <<"######\n"
#define debug1(x) cout <<"### " << x << " ###\n"
#define debug2(x,y) cout <<"# " << x <<" : "<< y <<" #\n"
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define rall(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 200005
#define INF 1000000009
#define MOD 998244353

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

template <typename T> string toString ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template<typename T> int toInt (T str) {
    stringstream ss;
    ss << str;
    int num;
    ss >> num;
    return num;
}
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
void fun (int n) {
    ll num = 1;

    for (int i = 1; i <= n; i++) {
        num *= 10LL;
    }

    vector<string>str[num];

    for (int i = 0; i < num; i++) {
        string s = toString (i);
        string ss = "";
        int x = n - (int) s.size();

        while (x--) {
            ss += '0';
        }

        ss += s;
        str[i].pb (ss);
    }

    map<int, int>mp;

    for (int j  = 0; j < num; j++) {
        int cnt = 1;
        string ss = str[j][0];

        for (int i = 1; i < (int) ss.size(); i++) {
            //~ cout << j << "\n";
            if (ss[i - 1] != ss[i]) {
                //~ if (cnt == 2) {
                //~ cout << i << "  :\n";
                //~ cout << str[j][i - 2] << " " << str[j][i - 1] << "\n";
                //~ }
                mp[cnt]++;
                cnt = 1;

            } else {
                cnt++;
            }
        }

        mp[cnt]++;
    }

    nl;

    for (int i = 1; i <= n; i++) {
        cout << mp[i] << ' ';
    }

    nl;
}
ll ten[MAX];
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    ten[0] = 1;

    for (int i = 1; i < MAX; i++) {
        ten[i] = (ten[i - 1] * 10) % MOD;
    }

    int n;
    cin >> n;

    //~ fun (n);
    for (int i = 1; i <= n; i++) {
        if (i == n) cout << 10 << "\n";
        else {
            ll tmp1 = (2 * 10 * 9LL * ten[n - i - 1]) % MOD;
            ll tmp2 =  ( (n - i - 1) * 10LL * 9 * 9 * ten[n - i - 2]) % MOD;
            ll res = (tmp1 + tmp2) % MOD;
            cout << res << " ";
        }
    }

    return 0;
}
