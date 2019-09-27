/***************************************************
 * Problem Name : D. Make The Fence Great Again.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-09-19
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
#define MAX 300005
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
ll ar[MAX], br[MAX];

struct st {
    int x, y;
    int val;
};

bool cmp (st a, st b) {
    return a.val < b.val;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int q, n;
    cin >> q;

    while (q--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i] >> br[i];
        }

        int k = 0;
        st res[MAX];

        for (int i = 1; i < n; i++) {
            if (ar[i] == ar[i - 1]) {
                res[k].x = i - 1;
                res[k].y = i;
                res[k].val = min (br[i], br[i - 1]);
                k++;
            }
        }

        sort (res, res + k, cmp);
        ll sum = 0;

        for (int i = 0; i < k; i++) {
            int x = res[i].x;
            int y = res[i].y;
            ll val = res[i].val;

            if (ar[x] != ar[y]) continue;

            if (val == br[x] && val != br[y]) {
                if (x == 0) {
                    sum += (val);
                    ar[x]++;

                } else {
                    if (ar[x] + 1 == ar[x - 1]) {
                        sum += (2LL * val);
                        ar[x] += 2;

                    } else {
                        sum += (val);
                        ar[x]++;
                    }
                }

            } else if (val == br[y] && val != br[x]) {
                //~ debug;
                if (y == n - 1) {
                    sum += (val);
                    ar[y]++;

                } else {
                    if (ar[y] + 1 == ar[y + 1]) {
                        sum += (2LL * val);
                        ar[y] += 2;

                    } else {
                        sum += (val);
                        ar[y]++;
                    }
                }

            } else {
                ll mn1 = 0, c1 = 0;

                if (x == 0) {
                    mn1 += (val);
                    c1 = 1;

                } else {
                    if (ar[x] + 1 == ar[x - 1]) {
                        mn1 += (2LL * val);
                        c1 = 2;

                    } else {
                        mn1 += (val);
                        c1 = 1;
                    }
                }

                ll mn2 = 0, c2 = 0;

                if (y == n - 1) {
                    mn2 += (val);
                    c2 = 1;

                } else {
                    if (ar[y] + 1 == ar[y + 1]) {
                        mn2 += (2LL * val);
                        c2 = 2;

                    } else {
                        mn2 += (val);
                        c2 = 1;
                    }
                }

                if (mn1 > mn2) {
                    sum += mn2;
                    ar[y] += c2;

                } else {
                    sum += mn1;
                    ar[x] += c1;
                }
            }
        }

        cout << sum << "\n";
    }

    return 0;
}
