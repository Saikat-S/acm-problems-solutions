/***************************************************
 * Problem Name : B. Filling the Grid.cpp
 * Problem Link : https://codeforces.com/contest/1228/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-09-29
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
#define MAX 1005
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
int aa[MAX][MAX];
int ar[MAX][MAX];
int br[MAX][MAX];

ll fun (ll n) {
    ll ans = 1LL;

    for (int i = 1; i <= n; i++) {
        ans = (ans * 2LL) % MOD;
    }

    return ans % MOD;
}


int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int h, w;
    int R[MAX], C[MAX];
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        cin >> R[i];

        for (int j = 0; j < R[i]; j++) {
            aa[i][j] = 1;
            ar[i][j] = 1;
        }
    }

    for (int j = 0; j < w; j++) {
        cin >> C[j];

        for (int i = 0; i < C[j]; i++) {
            aa[i][j] = 1;
            br[i][j] = 1;
        }
    }

    ll cnt = 0LL;
    bool flag = false;

    for (int i = 0; i < h; i++) {
        int sum = 0;

        for (int j = 0; j < w; j++) {
            if (aa[i][j] == 1) sum++;
            else break;
        }

        if (sum != R[i]) {
            flag = true;
            break;
        }
    }

    for (int j = 0; j < w; j++) {
        int sum = 0;

        for (int i = 0; i < h; i++) {
            if (aa[i][j] == 1) sum++;
            else break;
        }

        if (sum != C[j]) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << 0 << "\n";
        exit (0);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0 ; j < w; j++) {
            if (ar[i][j] == 0 && br[i][j] == 0) {
                if ( (i - 1) >= 0  && (j - 1) >= 0 && br[i - 1][j] == 0 && ar[i][j - 1] == 0) {
                    cnt++;
                }
            }
        }
    }

    //~ cout << cnt << "\n";
    ll ans = fun (cnt);
    cout << ans << "\n";
    return 0;
}
