/***************************************************
 * Problem Name : B. Restricted RPS.cpp
 * Problem Link : https://codeforces.com/contest/1245/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-11-01
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
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000009
#define MOD 1000000007

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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
char fun (char ch) {
    if (ch == 'R') return 'P';
    else if (ch == 'P') return 'S';

    return 'R';
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n, a, b, c;
    string str;
    cin >> tc;

    while (tc--) {
        cin >> n ;
        cin >> a >> b >> c;
        cin >> str;
        int wn = n / 2;

        if (n % 2 != 0) wn++;

        map<char, int>mm;

        for (int i = 0; i < n; i++) {
            mm[fun (str[i])]++;
        }

        int c1 = min (mm['R'], a);
        int c2 = min (mm['P'], b);
        int c3 = min (mm['S'], c);
        int cnt = c1 + c2 + c3;

        if (cnt >= wn) {
            map<char, int>mp;
            mp['R'] = a;
            mp['P'] = b;
            mp['S'] = c;

            for (int i = 0; i < n; i++) {
                char cc = fun (str[i]);

                if (mp[cc] != 0) {
                    mp[cc]--;
                }
            }

            queue<char>q;

            for (int i = 1; i <= mp['R']; i++) q.push ('R');

            for (int i = 1; i <= mp['S']; i++) q.push ('S');

            for (int i = 1; i <= mp['P']; i++) q.push ('P');

            string res = "";
            mp['R'] = a;
            mp['P'] = b;
            mp['S'] = c;

            for (int i = 0; i < n; i++) {
                char cc = fun (str[i]);

                if (mp[cc] != 0) {
                    res += cc;
                    mp[cc]--;

                } else {
                    cc = q.front();
                    res += cc;
                    q.pop();
                }
            }

            cout << "YES\n";
            cout << res << "\n";

        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
