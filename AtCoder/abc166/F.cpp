/***************************************************
 * Problem Name : F.cpp
 * Problem Link : https://atcoder.jp/contests/abc166/tasks/abc166_f
 * OJ           : atCoder
 * Verdict      : AC
 * Date         : 2020-05-03
 * Problem Type : ABC - F
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
vector<string>vec;
int n;
int dp[MAX][4][4][4];

int fun (int pos, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return 0;

    if (pos >= n) return 1;

    a = min (a, 3);
    b = min (b, 3);
    c = min (c, 3);
    
    int &res = dp[pos][a][b][c];
    
    if(res != -1)return res;
    
    
    bool flag = false;

    if (vec[pos] == "AB") {
        bool v1 = fun (pos + 1, a - 1, b + 1, c);
        bool v2 = fun (pos + 1, a + 1, b - 1, c);
        flag =  v1 | v2;

    } else if (vec[pos] == "AC") {
        bool v1 = fun (pos + 1, a - 1, b, c + 1);
        bool v2 = fun (pos + 1, a + 1, b, c - 1);
        flag = v1 | v2;

    } else {
        bool v1 = fun (pos + 1, a, b + 1, c - 1);
        bool v2 = fun (pos + 1, a, b - 1, c + 1);
        flag = v1 | v2;
    }

    return res = flag;
}

void path (int pos, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return;

    if (pos >= n) return;

    a = min (a, 3);
    b = min (b, 3);
    c = min (c, 3);
    if (vec[pos] == "AB") {
        bool v1 = fun (pos + 1, a - 1, b + 1, c);

        if (v1) {
            cout << "B\n";
            path (pos + 1, a - 1, b + 1, c);

        } else {
            cout << "A\n";
            path (pos + 1, a + 1, b - 1, c);
        }

    } else if (vec[pos] == "AC") {
        bool v1 = fun (pos + 1, a - 1, b, c + 1);

        if (v1) {
            cout << "C\n";
            path (pos + 1, a - 1, b, c + 1);

        } else {
            cout << "A\n";
            path (pos + 1, a + 1, b, c - 1);
        }

    } else {
        bool v1 = fun (pos + 1, a, b + 1, c - 1);

        if (v1) {
            cout << "B\n";
            path (pos + 1, a, b + 1, c - 1);

        } else {
            cout << "C\n";
            path (pos + 1, a, b - 1, c + 1);
        }
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int a, b, c;
    cin >> n >> a >> b >> c;
    vec.resize (n);

    for (auto &v : vec) cin >> v;
    SET(dp, -1);
    if (fun (0, a, b, c) ) {
        cout << "Yes\n";
        path (0, a, b, c);

    } else {
        cout << "No\n";
    }

    return 0;
}
