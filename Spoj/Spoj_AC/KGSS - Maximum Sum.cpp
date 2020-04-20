/***************************************************
 * Problem Name : KGSS - Maximum Sum.cpp
 * Problem Link : https://www.spoj.com/problems/KGSS/en/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2020-04-18
 * Problem Type : Segement Tree
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
pair<int, int> tr[4 * MAX];
int ar[MAX];
pii combine (pii a, pii b) {
    pii tmp;

    if (a.first > b.first) {
        tmp.first = a.first;
        tmp.second = max3 (a.second, b.first, b.second);

    } else {
        tmp.first = b.first;
        tmp.second = max3 (a.first, a.second, b.second);
    }

    return tmp;
}

void build (int nod, int low, int high) {
    if (low == high) {
        tr[nod] = {ar[low], -1};
        return;

    } else {
        int mid = (low + high) / 2;
        build (nod * 2, low, mid);
        build (nod * 2 + 1, mid + 1, high);
        tr[nod] = combine (tr[nod * 2], tr[nod * 2 + 1]);
    }
}

pair<int, int>  query (int nod, int low, int high, int qlow, int qhigh) {
    if (low > high || high < qlow || low > qhigh) {
        return make_pair (-1, -1);
    }

    if (low >= qlow && qhigh >= high) {
        return tr[nod];
    }

    int mid = (low + high) / 2;
    return combine (query (nod * 2, low, mid, qlow, qhigh ),
                    query (nod * 2 + 1, mid + 1, high, qlow, qhigh) );
}

void update (int nod, int low, int high, int pos, int new_val) {
    if (low == high) {
        tr[nod] = {new_val, -1};

    } else {
        int mid = (low + high) / 2;

        if (pos <= mid) {
            update (nod * 2, low, mid, pos, new_val);

        } else {
            update (nod * 2 + 1, mid + 1, high, pos, new_val);
        }

        tr[nod] = combine (tr[nod * 2], tr[nod * 2 + 1]);
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int n, q;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build (1, 0, n - 1);
    cin >> q;

    while (q--) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;

        if (ch == 'U') {
            update (1, 0, n - 1, l - 1, r);

        } else {
            pii tmp = query (1, 0, n - 1, l - 1, r - 1);
            cout << tmp.first + tmp.second << "\n";
        }
    }

    return 0;
}
