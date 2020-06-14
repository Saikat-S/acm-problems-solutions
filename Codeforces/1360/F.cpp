/***************************************************
 * Problem Name : F.cpp
 * Problem Link : https://codeforces.com/contest/1360/problem/F
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-05-24
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
#define F first
#define S second
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
vector<string>vec;
int n, m;

int dp[13][1030][3];

int Set (int N, int pos) {
    return N = (N | (1 << pos) );
}
bool check (int N, int pos) {
    return (bool) (N & (1 << pos) );
}

int fun (int pos, int mask, int cnt) {
    if (pos >= m) {
        if (cnt >= 1) return 0;
        else return 1;
    }

    int &res = dp[pos][mask][cnt];

    if (res != -1) return res;

    res = 0;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int f = 1;
        int new_mask = mask;

        for (int i = 0; i < n; i++) {
            int v = 0;

            if (vec[i][pos] != ch) {
                if (check (mask, i) == 0) {
                    new_mask = Set (new_mask, i);
                    v = fun (pos + 1, new_mask, cnt | 0);

                } else {
                    v = fun (pos + 1, new_mask, 1 | cnt);
                }

            } else {
                v = fun (pos + 1, new_mask, cnt);
            }

            f = f & v;
        }

        res = res | f;
    }

    return res;
}
void path (int pos, int mask, int cnt) {
    if (pos >= m) {
        return ;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int f = 1;
        int new_mask = mask;

        for (int i = 0; i < n; i++) {
            int v = 0;

            if (vec[i][pos] != ch) {
                if (check (mask, i) == 0) {
                    new_mask = Set (new_mask, i);
                    v = fun (pos + 1, new_mask, cnt | 0);

                } else {
                    v = fun (pos + 1, new_mask, 1 | cnt);
                }

            } else {
                v = fun (pos + 1, new_mask, cnt);
            }

            f = f & v;
        }

        if (f) {
            cout << ch;
            path (pos + 1, new_mask, 0);
            return;
        }
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        vec.resize (n);

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        SET (dp, -1);
        int res = fun (0, 0, 0);

        if (res != 1) {
            cout << -1 << "\n";

        } else {
            path (0, 0, 0);
            nl;
        }

        vec.clear();
    }

    return 0;
}
