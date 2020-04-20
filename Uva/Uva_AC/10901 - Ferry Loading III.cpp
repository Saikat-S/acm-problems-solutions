/***************************************************
 * Problem Name : 10901 - Ferry Loading III.cpp
 * Problem Link : https://onlinejudge.org/external/109/10901.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2020-03-28
 * Problem Type : STL
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
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;
    int tt = 1;

    while (tc--) {
        int n, t, m;
        cin >> n >> t >> m;
        queue<pii>left, right;

        for (int i = 0; i < m; i++) {
            int av_time;
            string str;
            cin >> av_time >> str;

            if (str == "left") {
                left.push ({av_time, i});

            } else {
                right.push ({av_time, i});
            }
        }

        int cur_time = 0;
        bool pos = false;
        vector<int>vec (m);

        while (1) {
            if (left.empty() && right.empty() ) {
                break;
            }

            if (!pos) {
                int cnt = 0;

                while (!left.empty() ) {
                    if (left.front().first <= cur_time && cnt < n) {
                        cnt++;
                        int x = left.front().second;
                        vec[x] = (cur_time + t);
                        left.pop();

                    } else {
                        break;
                    }
                }

                if (cnt == 0) {
                    int l  = INF, r = INF;

                    if (!left.empty() ) {
                        l = left.front().first;
                    }

                    if (!right.empty() ) {
                        r = right.front().first;
                    }

                    if (l <= r) {
                        pos = false;
                        cur_time = max (l, cur_time);

                    } else {
                        pos = true;
                        cur_time = max (r, cur_time) + t;
                    }

                } else {
                    pos = true;
                    cur_time += t;
                }

            } else {
                int cnt = 0;

                while (!right.empty() ) {
                    if (right.front().first <= cur_time && cnt < n) {
                        cnt++;
                        int x = right.front().second;
                        vec[x] = (cur_time + t);
                        right.pop();

                    } else {
                        break;
                    }
                }

                if (cnt == 0) {
                    int l  = INF, r = INF;

                    if (!left.empty() ) {
                        l = left.front().first;
                    }

                    if (!right.empty() ) {
                        r = right.front().first;
                    }

                    if (l < r) {
                        pos = false;
                        cur_time = max (l, cur_time) + t;

                    } else {
                        pos = true;
                        cur_time = max (r, cur_time);
                    }

                } else {
                    pos = false;
                    cur_time += t;
                }
            }
        }

        if (tt != 1) nl;

        tt++;

        for (int i  = 0; i < (int) vec.size(); i++) {
            cout << vec[i] << "\n";
        }
    }

    return 0;
}
