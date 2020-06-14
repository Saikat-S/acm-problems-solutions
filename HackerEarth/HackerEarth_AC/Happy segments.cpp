/***************************************************
 * Problem Name : Happy segments.cpp
 * Problem Link : https://www.hackerearth.com/problem/algorithm/happy-segments-e290faa6/
 * OJ           :
 * Verdict      : AC
 * Date         : 2020-05-01
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
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 500005
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
struct query {
    int id, l, r;
} Q[MAX];

int ar[MAX], hr[MAX], Count[MAX], A[MAX];
int n, q, blockSz;
int L = 0, R = -1;

bool cmp (query a, query b) {
    int block_a = a.l / blockSz;
    int block_b = b.l / blockSz;

    if (block_a == block_b) return a.r < b.r;
    else return block_a < block_b;
}
void MOS() {
    sort (Q, Q + q, cmp);
    L = 0, R = -1;
    for (int i = 0; i < q; i++) {
        while (R < Q[i].r) {
            R++;
            Count[ar[R]]++;
        }

        while (R > Q[i].r) {
            Count[ar[R]]--;
            R--;
        }

        while (L < Q[i].l) {
            Count[ar[L]]--;
            L++;
        }

        while (L > Q[i].l) {
            L--;
            Count[ar[L]]++;
        }

        bool sum = true;

        for (int j = Q[i].l; j <= Q[i].r; j++) {
            if (Count[ar[j]] != hr[ar[j]]) {
                sum = false;
                break;
            }
        }

        int id = Q[i].id;

        if (sum) {
            A[id] = 1;

        } else {
            A[id] = 0;
        }
    }
}
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int m;
    cin >> n >> m;
    blockSz = (int) sqrt (n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> hr[i];
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].id = i;
    }

    MOS();

    for (int i = 0; i < q; i++) {
        cout << A[i] << "\n";
    }

    return 0;
}
