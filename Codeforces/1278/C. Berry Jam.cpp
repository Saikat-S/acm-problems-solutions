/***************************************************
 * Problem Name : C. Berry Jam.cpp
 * Problem Link : https://codeforces.com/contest/1278/problem/C
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-12-19
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
int ar[MAX];
vector<int>v1, v2, vO, vT;
int n;
int res;
bool fun (int mid) {
    bool flag = false;

    for (int i = 0; i <= n; i++) {
        int x = v1[i];
        int y = v2[i];

        if (x <= mid && y <= mid) {
            int xx = lower_bound (all (vO), mid - x) - vO.begin();
            int yy = lower_bound (all (vT), mid - y) - vT.begin();
            int x1, y1;

            if (xx > n) {
                x1 = MAX;
                y1 = MAX;

            } else {
                x1 = x + vO[xx];
                y1 = y + vT[xx];
            }

            int x2, y2;

            if (yy > n) {
                x2 = MAX;
                y2 = MAX;

            } else {
                x2 = x + vO[yy];
                y2 = y + vT[yy];
            }

            if (x1 == mid && y1 == mid) {
                int X = (2 * n) - (i + xx);
                res = min (res, X);
                flag = true;
            }

            if (x2 == mid &&  y2 == mid) {
                int X = (2 * n) - (i + yy);
                res = min (res, X);
                flag = true;
            }

            if (flag) break;
        }
    }

    return flag;
}

void bi (int val) {
    int low = 0, high = val;

    while (high >= low) {
        int mid = (high + low) / 2;

        if (fun (mid) ) {
            low = mid + 1;

        } else {
            high = mid - 1;
        }
    }
}


int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;

        for (int i = 1; i <= 2 * n; i++) {
            cin >> ar[i];
        }

        int cnt1 = 0, cnt2 = 0;
        vO.pb (0);
        vT.pb (0);

        for (int i = 1; i <= n; i++) {
            if (ar[i] == 1) {
                cnt1++;
                vO.pb (cnt1);
                vT.pb (cnt2);

            } else {
                cnt2++;
                vO.pb (cnt1);
                vT.pb (cnt2);
            }
        }

        cnt1 = 0, cnt2 = 0;
        v1.pb (0);
        v2.pb (0);

        for (int i = 2 * n; i > n; i--) {
            if (ar[i] == 1) {
                cnt1++;
                v1.pb (cnt1);
                v2.pb (cnt2);

            } else {
                cnt2++;
                v1.pb (cnt1);
                v2.pb (cnt2);
            }
        }

        res = INF;
        bi (2 * n);
        cout << res << "\n";
        vO.clear(), vT.clear();
        v1.clear(), v2.clear();
    }

    return 0;
}
