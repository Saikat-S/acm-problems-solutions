/***************************************************
 * Problem Name : 1097 - Lucky Number.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1097
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-12-04
 * Problem Type : Data Structure (Segment Tree)
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
#define MAX 1500005
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
ll ar[750010];
ll tr[750010 * 4];
int pre_cal() {
    int k = 0;

    for (int i = 1; i < MAX; i += 2) {
        ar[k++] = i;
    }

    return k;
}

void build (int nod, int low, int high) {
    if (low > high) {
        return;
    }

    if (low == high) {
        tr[nod] = 1;
        return;
    }

    int mid = (high + low) / 2;
    build (nod * 2, low, mid);
    build (nod * 2 + 1, mid + 1, high);
    tr[nod] = tr[nod * 2] + tr[nod * 2 + 1];
}

void update (int nod, int low, int high, int pos, int v) {
    if (low > high) {
        return;
    }

    if (low == high) {
        if (pos == low) tr[nod] = v;

        return;
    }

    int mid = (low + high) / 2;

    if (pos <= mid) {
        update (nod * 2, low, mid, pos, v);

    } else {
        update (nod * 2 + 1, mid + 1, high, pos, v);
    }

    tr[nod] = tr[nod * 2] + tr[nod * 2 + 1];
}

int query (int nod, int low, int high, int  cnt) {
    if (low > high) {
        return MAX;
    }

    if (low == high) {
        return low;
    }

    int mid = (high + low) / 2;
    int ans;

    if (tr[nod * 2] >= cnt) {
        ans = query (nod * 2, low, mid, cnt);

    } else {
        ans = query (nod * 2 + 1, mid + 1, high, cnt - tr[nod * 2]);
    }

    return ans;
}
int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n = pre_cal();
    build (1, 0, n - 1);
    int pos = 2;

    while (1) {
        int nth = query (1, 0, n - 1, pos);
        int num = ar[nth];

        if (num > 100000) break;

        int st = num;
        int p = query (1, 0, n - 1, st);
        int cnt = 0;

        while (1) {
            update (1, 0, n - 1, p, 0);
            ar[p] = 0;
            cnt++;
            st += num;

            if (st > 1000000) break;

            p =  query (1, 0, n - 1, st - cnt);
        }

        pos++;
    }

    int tc;
    si (tc);

    for (int t = 1; t <= tc; t++) {
        int N;
        si (N);
        int nth = query (1, 0, n - 1, N);
        printf ("Case %d: %lld\n", t, ar[nth]);
    }

    return 0;
}
