/***************************************************
 * Problem Name : D. Restore Permutation.cpp
 * Problem Link : https://codeforces.com/contest/1208/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-08-26
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
#define pii pair<ll,ll>
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
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 2000005
#define INF 1e13 + 5
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
ll ar[MAX], tr[MAX * 4], lazy[MAX * 4];
void build (int nod, int low, int high) {
    if (low > high) return ;

    if (low == high) {
        tr[nod] = ar[low];
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
    tr[nod] = min (tr[left], tr[right]);
}
int query (int nod, int low, int high) {
    if (low > high) {
        return 0;
    }

    if (lazy[nod] != 0) {
        int left = nod * 2;
        int right = nod * 2 + 1;

        if (low != high) {
            tr[left] += lazy[nod];
            tr[right] += lazy[nod];
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];

        } else {
            tr[left] += lazy[nod];
            tr[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low == high) {
        return low;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    int ans = -1;

    if (tr[right] == 0) {
        ans = query (right, mid + 1, high);

    } else {
        ans = query (left, low, mid);
    }

    tr[nod] = min (tr[left], tr[right]);
    return ans;
}
void update (int nod, int low, int high, int qlow, int qhigh, ll val) {
    if (low > high) return ;

    if (lazy[nod] != 0) {
        int left = nod * 2;
        int right = nod * 2 + 1;

        if (low != high) {
            tr[left] += lazy[nod];
            tr[right] += lazy[nod];
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];

        } else {
            tr[left] += lazy[nod];
            tr[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low > qhigh || high < qlow) {
        return;
    }

    if (low >= qlow && high <= qhigh) {
        tr[nod] += (val);
        int left = nod * 2;
        int right = nod * 2 + 1;

        if (low != high) {
            tr[left] += val;
            tr[right] += val;
            lazy[left] += val;
            lazy[right] += val;

        } else {
            tr[left] += val;
            tr[right] += val;
        }

        return;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    update (left, low, mid, qlow, qhigh, val);
    update (right, mid + 1, high, qlow, qhigh, val);
    tr[nod] = min (tr[left], tr[right]);
}


int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n;
    cin >> n ;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build (1, 0, n - 1);
    int final_ar[MAX];

    for (int i = 1; i <= n; i++) {
        int x = query (1, 0, n - 1);
        final_ar[x] = i;
        update (1, 0, n - 1, x, x, INF);
        update (1, 0, n - 1, x + 1, n - 1, -i);
    }

    for (int i = 0; i < n; i++) {
        cout << final_ar[i] << " ";
    }

    nl;
    return 0;
}
