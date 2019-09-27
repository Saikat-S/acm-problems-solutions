/***************************************************
 * Problem Name : C. White Sheet.cpp
 * Problem Link : https://codeforces.com/contest/1216/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-09-21
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
bool isInside (int x1, int y1, int x2,
               int y2, int x, int y) {
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        return true;

    } else {
        return false;
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int x1, x2, x3, x4, x5, x6;
    int y1, y2, y3, y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    x1 *= 2; x2 *= 2, x3 *= 2, x4 *= 2, x5 *= 2, x6 *= 2;
    y1 *= 2, y2 *= 2, y3 *= 2, y4 *= 2, y5 *= 2, y6 *= 2;

    for (int x = x1; x <= x2; x++) {
        if (!isInside (x3, y3, x4, y4, x, y1)
            && !isInside (x5, y5, x6, y6, x, y1) ) {
            cout << "YES\n";
            exit (0);
        }

        if (!isInside (x3, y3, x4, y4, x, y2)
            && !isInside (x5, y5, x6, y6, x, y2) ) {
            cout << "YES\n";
            exit (0);
        }
    }

    for (int y = y1; y <= y2; y++) {
        if (!isInside (x3, y3, x4, y4, x1, y)
            && !isInside (x5, y5, x6, y6, x1, y) ) {
            cout << "YES\n";
            exit (0);
        }

        if (!isInside (x3, y3, x4, y4, x2, y)
            && !isInside (x5, y5, x6, y6, x2, y) ) {
            cout << "YES\n";
            exit (0);
        }
    }

    cout << "NO\n";
    return 0;
}
