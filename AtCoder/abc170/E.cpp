/***************************************************
 * Problem Name : E.cpp
 * Problem Link : https://atcoder.jp/contests/abc170/tasks/abc170_e
 * OJ           : atCoder
 * Verdict      : AC
 * Date         : 2020-06-14
 * Problem Type : abc - E
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
#define F first
#define S second
#define MAX 200005
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
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
multiset<int>st_r[MAX];
int mp[MAX];
int ra[MAX];
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int n, q;
    cin >> n >> q;
    set<int>st;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        st_r[b].insert (a);
        st.insert (b);
        ra[i] = a;
        mp[i] = b;
    }

    multiset<int>ans;

    for (auto it : st) {
        if ( (int) st_r[it].size() == 0) continue;

        auto it1 = st_r[it].end();
        it1--;
        int val = *it1;
        ans.insert (val);
    }

    while (q--) {
        int c, d;
        cin >> c >> d;
        int x = mp[c];  // c belong x kinder
        int r = ra[c];

        if (x == d) {
            cout << *ans.begin() << "\n";

        } else {
            // remove from ans
            if ( (int) st_r[x].size() != 0) {
                auto it1 = st_r[x].end();
                it1--;
                int val = *it1;
                auto it = ans.find (val);

                if (it != ans.end() ) ans.erase (it);
            }

            if ( (int) st_r[d].size() != 0) {
                auto it1 = st_r[d].end();
                it1--;
                int val = *it1;
                auto it = ans.find (val);

                if (it != ans.end() ) ans.erase (it);
            }

            mp[c] = d;
            auto it = st_r[x].find (r);

            if (it != st_r[x].end() ) {
                st_r[x].erase (it);
            }

            // add c to d
            st_r[d].insert (r);

            // add to ans
            if ( (int) st_r[x].size() != 0) {
                auto it1 = st_r[x].end();
                it1--;
                int val = *it1;
                ans.insert (val);
            }

            if ( (int) st_r[d].size() != 0) {
                auto it1 = st_r[d].end();
                it1--;
                int val = *it1;
                ans.insert (val);
            }

            cout << *ans.begin() << "\n";
        }
    }

    return 0;
}
