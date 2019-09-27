/***************************************************
 * Problem Name : C. Swap Letters.cpp
 * Problem Link : https://codeforces.com/contest/1215/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-09-15
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
set<int>sa, sb, ta, tb;
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    map<char, int>mp;;

    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        mp[t[i]]++;

        if (s[i] != t[i]) {
            if (s[i] == 'a') sa.insert (i);
            else sb.insert (i);

            if (t[i] == 'a') ta.insert (i);
            else tb.insert (i);
        }
    }

    if (mp['a'] & 1 || mp['b'] & 1) {
        cout << -1 << "\n";
        exit (0);
    }

    vector<pii>ans;

    for (int i = 0; i < n;) {
        if (s[i] != t[i]) {
            if (s[i] == 'a') {
                if ( (int) sa.size() > 1) {
                    // make t[i] = 'a';
                    auto it = sa.begin();

                    if (*it == i) it++;

                    ans.pb ({*it, i});
                    swap (s[*it], t[i]);
                    sa.erase (it);
                    sa.erase (sa.find (i) );
                    tb.erase (tb.find (i) );
                    tb.erase (tb.find (*it) );
                    i++;

                } else if ( (int) tb.size() > 1) {
                    //~ make s[i] = 'b'
                    auto it = tb.begin();

                    if (*it == i) it++;

                    ans.pb ({i, *it});
                    swap (s[i], t[*it]);
                    tb.erase (it);
                    tb.erase (tb.find (i) );
                    sa.erase (sa.find (i) );
                    sa.erase (sa.find (*it) );
                    i++;

                } else {
                    swap (s[i], t[i]);
                    ans.pb ({i, i});
                    sa.erase (sa.find (i) );
                    tb.erase (tb.find (i) );
                    sb.insert (i);
                    ta.insert (i);
                }

            } else {
                //~ s[i] == 'b'
                if ( (int) sb.size() > 1) {
                    //~ make t[i] = 'b'
                    auto it = sb.begin();

                    if (*it == i) it++;

                    ans.pb ({*it, i});
                    swap (s[*it], t[i]);
                    sb.erase (it);
                    sb.erase (sb.find (i) );
                    //~ debug;
                    ta.erase (ta.find (i) );
                    ta.erase (ta.find (*it) );
                    i++;

                } else if ( (int) ta.size() > 1) {
                    //~ make s[i] = 'a'
                    auto it = ta.begin();

                    if (*it == i) it++;

                    ans.pb ({i, *it});
                    swap (s[i], t[*it]);
                    ta.erase (it);
                    ta.erase (ta.find (i) );
                    sa.erase (sa.find (i) );
                    sa.erase (sa.find (*it) );
                    i++;

                } else {
                    swap (s[i], t[i]);
                    ans.pb ({i, i});
                    sb.erase (sb.find (i) );
                    ta.erase (ta.find (i) );
                    sa.insert (i);
                    tb.insert (i);
                }
            }

        } else {
            i++;
        }
    }

    cout << (int) ans.size() << "\n";

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

    return 0;
}
