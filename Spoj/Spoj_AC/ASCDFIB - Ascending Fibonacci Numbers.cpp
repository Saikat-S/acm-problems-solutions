/***************************************************
 * Problem Name : ASCDFIB - Ascending Fibonacci Numbers.cpp
 * Problem Link : https://www.spoj.com/problems/ASCDFIB/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2019-09-21
 * Problem Type : Number Theory + Sorting(Counting Sort)
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
#define MOD 100000

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
pii fib (int n) {
    int a = 0, b = 1;

    for (int i = 3 ; i <= n; i++) {
        int c = (a + b) % MOD;
        a = b;
        b = c;
    }

    return {a, b};
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, a, b;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> a >> b;
        vector<int>vec;

        if (a == 1) {
            int n1 = 0;
            int n2 = 1;
            vec.pb (n1);

            if (b > 0) vec.pb (n2);

            for (int i = 2; i <= b; i++) {
                int n3 = (n1 + n2) % MOD;
                vec.pb (n3);
                n1 = n2;
                n2 = n3;
            }

        } else if (a == 2) {
            int n1 = 1;
            int n2 = 1;
            vec.pb (n1);

            if (b > 0) vec.pb (n2);

            for (int i = 2; i <= b; i++) {
                int n3 = (n1 + n2) % MOD;
                vec.pb (n3);
                n1 = n2;
                n2 = n3;
            }

        } else {
            pii pi = fib (a);
            int n1 = pi.second;
            int n2 = (pi.first + pi.second) % MOD;
            vec.pb (n1);

            if (b > 0) vec.pb (n2);

            for (int i = 2; i <= b; i++) {
                int n3 = (n1 + n2) % MOD;
                vec.pb (n3);
                n1 = n2;
                n2 = n3;
            }
        }

        int ar[MAX];
        SET (ar, 0);

        for (int i = 0; i < (int) vec.size(); i++) {
            ar[vec[i]]++;
        }

        cout << "Case " << t << ": ";
        int cnt = 0;

        for (int i = 0; i < MAX; i++) {
            for (int j = 1; j <= ar[i]; j++) {
                cout << i << " ";
                cnt++;

                if (cnt >= 100) break;
            }

            if (cnt >= 100) break;
        }

        nl;
    }

    return 0;
}
