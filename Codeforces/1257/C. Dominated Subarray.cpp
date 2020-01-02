/***************************************************
 * Problem Name : C. Dominated Subarray.cpp
 * Problem Link : https://codeforces.com/contest/1257/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-11-13
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n;
    int ar[MAX];
    cin >> tc;

    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        if (n == 1) {
            cout << "-1\n";
            continue;
        }

        multiset<int>st;
        int mp[MAX];
        SET (mp, 0);
        int l = 0, r = 1;

        if (ar[l] == ar[r]) {
            st.insert (2);
            mp[ar[l]] = 2;

        } else {
            st.insert (1);
            st.insert (1);
            mp[ar[l]] = 1;
            mp[ar[r]] = 1;
        }

        int ans = INF;

        while (1) {
            auto it = st.end();
            it--;
            int x1 = *it;
            int x2 = 0;

            if ( (int) st.size() >= 2) {
                it--;
                x2 = *it;
            }
            if (x1 > x2) {
                ans = min (ans, (r - l) + 1);
                int val = ar[l];
                it = st.find (mp[val]);
                st.erase (it);
                mp[val]--;

                if (mp[val] != 0) {
                    st.insert (mp[val]);
                }

                l++;

                if (l == r) {
                    break;
                }

            } else {
                r++;

                if (r >= n) break;

                int val = ar[r];

                if (mp[val] == 0) {
                    mp[val] = 1;
                    st.insert (mp[val]);

                } else {
                    it = st.find (mp[val]);
                    st.erase (it);
                    mp[val]++;
                    st.insert (mp[val]);
                }
            }
        }

        if (ans == INF) {
            cout << "-1\n";

        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}
