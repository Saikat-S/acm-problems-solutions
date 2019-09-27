/***************************************************
 * Problem Name : E. Copying Data.cpp
 * Problem Link : https://codeforces.com/contest/292/problem/E
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-09-12
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int ar[MAX], br[MAX];
pii tr [MAX * 3], lazy [MAX * 3];
void build (int nod, int low, int high) {
    if (low > high) return ;

    if (low == high) {
        tr[nod] = {-1, -1};
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
}
pii query (int nod, int low, int high, int i) {
    if (low > high || low > i || high < i) {
        return {-2, -2};
    }

    if (lazy[nod].first != -1) {
        tr[nod].first = lazy[nod].first;
        tr[nod].second = lazy[nod].second;

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] = lazy[nod];
            lazy[right] =  lazy[nod];
        }

        lazy[nod] = {-1, -1};
    }

    if (low >= i && high <= i) {
        return tr[nod];
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;

    if (i <= mid) {
        return query (left, low, mid, i);

    } else {
        return query (right, mid + 1, high, i);
    }
}
void update (int nod, int low, int high, int qlow, int qhigh, int a, int b) {
    if (low > high) return ;

    if (lazy[nod].first != -1) {
        tr[nod] = lazy[nod];

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] = lazy[nod];
            lazy[right] = lazy[nod];
        }

        lazy[nod] = {-1, -1};
    }

    if (low > qhigh || high < qlow) {
        return;
    }

    if (low >= qlow && high <= qhigh) {
        tr[nod] = {a, b};

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] = {a, b};
            lazy[right] = {a, b};
        }

        return;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    update (left, low, mid, qlow, qhigh, a, b);
    update (right, mid + 1, high, qlow, qhigh, a, b);
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> br[i];
    }

    for (int i = 0; i < 3 * MAX; i++) {
        lazy[i] = {-1, -1};
    }

    build (1, 0, n - 1);

    while (m--) {
        int c;
        cin >> c;

        if (c == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            update (1, 0, n - 1, y, y + k - 1, x, y);

        } else {
            int ind;
            cin >> ind;
            ind--;
            pii qu = query (1, 0, n - 1, ind);
            int xx = qu.first;
            int yy = qu.second;

            if (qu.first == -1) {
                cout << br[ind] << "\n";

            } else {
                int pos = ind - yy;
                cout << ar[xx + pos] << "\n";
            }
        }
    }

    return 0;
}

