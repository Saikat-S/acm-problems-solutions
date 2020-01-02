/***************************************************
 * Problem Name : C - Strawberry Cakes .cpp
 * Problem Link :
 * Contest Name :
 * OJ           :
 * Verdict      : AC
 * Date         : 2019-11-23
 * Problem Type :
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
#define MAX 305
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
char str[MAX][MAX];
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int h, w, k;
    cin >> h >> w >> k;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> str[i][j];
        }
    }

    int ans[MAX][MAX];
    SET (ans, 0);
    int cnt = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (str[i][j] == '#') {
                ans[i][j] = cnt++;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ans[i][j] != 0) {
                for (int x = j - 1; x >= 0; x--) {
                    if (ans[i][x] != 0) break;

                    ans[i][x] = ans[i][j];
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w ; j++) {
            if (ans[i][j] == 0) {
                if (j > 0) {
                    ans[i][j] = ans[i][j - 1];

                } else if (i > 0) {
                    ans[i][j] = ans[i - 1][j];
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w ; j++) {
            if (ans[i][j] == 0) {
                int x = 0;

                for (int ii = i; ii < h; ii++) {
                    if (ans[ii][j] != 0) {
                        x = ans[ii][j];
                        break;
                    }
                }

                if (x != 0) {
                    ans[i][j] = x;

                } else {
                    for (int ii = i; ii >= 0; ii--) {
                        if (ans[ii][j] != 0) {
                            x = ans[ii][j];
                            break;
                        }
                    }

                    ans[i][j] = x;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j] << " ";
        }

        nl;
    }

    return 0;
}
