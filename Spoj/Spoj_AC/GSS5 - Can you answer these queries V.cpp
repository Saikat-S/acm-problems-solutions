/***************************************************
 * Problem Name : GSS5 - Can you answer these queries V.cpp
 * Problem Link : https://www.spoj.com/problems/GSS5/en/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2020-04-18
 * Problem Type : Segemen Tree
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
struct Node {
    ll left_sum, right_sum, total_sum, max_sum;
    Node() {
        left_sum = -INF;
        right_sum = -INF;
        total_sum = 0;
        max_sum = -INF;
    }
} tr[MAX * 4];

ll ar[MAX];


Node combine (Node a, Node b) {
    Node tmp;
    tmp.left_sum = max (a.left_sum, a.total_sum + b.left_sum);
    tmp.right_sum = max (b.right_sum, b.total_sum + a.right_sum);
    tmp.total_sum = a.total_sum + b.total_sum;
    tmp.max_sum = max3 (a.max_sum, b.max_sum, (a.right_sum + b.left_sum) );
    return tmp;
}

void build (int nod, int low, int high) {
    if (low > high) return;

    if (low == high) {
        tr[nod].left_sum = ar[low];
        tr[nod].right_sum = ar[low];
        tr[nod].total_sum = ar[low];
        tr[nod].max_sum = ar[low];
        return;
    }

    int mid = (high + low) / 2;
    build (nod * 2, low, mid);
    build (nod * 2 + 1, mid + 1, high);
    tr[nod] = combine (tr[nod * 2], tr[nod * 2 + 1]);
}
Node query (int nod, int low, int high, int qlow, int qhigh) {
    if (qlow > high || qhigh < low) {
        Node tmp;
        return tmp;
    }

    if (low >= qlow && high <= qhigh) {
        return tr[nod];
    }

    int mid = (high + low) / 2;
    Node a = query (nod * 2, low, mid, qlow, qhigh);
    Node b = query (nod * 2 + 1, mid + 1, high, qlow, qhigh);
    Node res = combine (a, b);
    return res;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    int n;
    cin >> tc;

    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        build (1, 0, n - 1);
        int q;
        cin >> q;

        while (q--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            ll ans = 0;

            if (y1 >= x2) {
                Node res1 = query (1, 0, n - 1, x1, x2 - 1);
                Node res2 = query (1, 0, n - 1, x2, y2);
                ans = res1.right_sum + res2.left_sum;
                res1 = query (1, 0, n - 1, x2, y1);
                res2 = query (1, 0, n - 1, y1 + 1, y2);
                ans = max (ans, res1.right_sum + res2.left_sum);
                res1 = query (1, 0, n - 1, x2, y1);
                ans = max (ans, res1.max_sum);

            } else {
                Node res1 = query (1, 0, n - 1, x1, y1);
                Node res2 = query (1, 0, n - 1, y1 + 1, x2 - 1);
                Node res3 = query (1, 0, n - 1, x2, y2);
                ans = res1.right_sum + res2.total_sum + res3.left_sum;
            }

            cout << ans << "\n";
        }
    }

    return 0;
}
