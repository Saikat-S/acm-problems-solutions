/***************************************************
 * Problem Name : Digit Printing.cpp
 * Problem Link : https://toph.co/p/digit-printing
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-09-14
 * Problem Type : Easy
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
void fun (char n, int x) {
    if (n == '0') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "* *";
        else if (x == 3) cout << "* *";
        else if (x == 4) cout << "* *";
        else cout << "***";

    } else if (n == '1') {
        if (x == 1) cout << " * ";
        else if (x == 2) cout << " * ";
        else if (x == 3) cout << " * ";
        else if (x == 4) cout << " * ";
        else cout << " * ";

    } else if (n == '2') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "  *";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "*  ";
        else cout << "***";

    } else if (n == '3') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "  *";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "  *";
        else cout << "***";

    } else if (n == '4') {
        if (x == 1) cout << "* *";
        else if (x == 2) cout << "* *";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "  *";
        else cout << "  *";

    } else if (n == '5') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "*  ";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "  *";
        else cout << "***";

    } else if (n == '6') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "*  ";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "* *";
        else  cout << "***";

    } else if (n == '7') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "  *";
        else if (x == 3) cout << "  *";
        else if (x == 4) cout << "  *";
        else cout << "  *";

    } else if (n == '8') {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "* *";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "* *";
        else cout << "***";

    } else {
        if (x == 1) cout << "***";
        else if (x == 2) cout << "* *";
        else if (x == 3) cout << "***";
        else if (x == 4) cout << "  *";
        else cout << "  *";
    }
}


int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;'
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        char ch;
        ll a, b;
        cin >> a >> ch >> b;
        ll ans ;

        if (ch == '+') {
            ans = a + b;

        } else if (ch == '-') {
            if (b > a) swap (a, b);

            ans = a - b;

        } else {
            ans = a * b;
        }

        ans = abs (ans);
        string str = toString (ans);
        cout << "Case #" << t << ":\n";

        for (int i = 1; i <= 5; i++) {
            for (int j = 0; j < (int) str.size(); j++) {
                if (j != 0) cout << " ";

                fun (str[j], i);
            }

            nl;
        }

        if (t != tc) nl;
    }

    return 0;
}
