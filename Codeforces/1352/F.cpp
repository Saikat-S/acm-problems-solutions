/***************************************************
 * Problem Name : F.cpp
 * Problem Link : https://codeforces.com/contest/1352/problem/F
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-05-10
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
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define F first
#define S second
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
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<char>vec;

        if (n2 == 0) {
            if (n1) {
                for (int i = 0; i <= n1; i++) {
                    vec.pb ('0');
                }

            } else {
                for (int i = 0; i <= n3; i++) {
                    vec.pb ('1');
                }
            }

        } else {
            for (int i = 0; i < (n2 + 1); i++) {
                if (i & 1) vec.pb ('0');
                else vec.pb ('1');
            }

            for (int i = 1; i <= n1; i++) {
                vec.insert (vec.begin() + 1, '0');
            }

            for (int i = 1; i <= n3; i++) {
                vec.insert (vec.begin() + 0, '1');
            }
        }

        //~ int a = 0, b = 0, c = 0;

        //~ for (int i = 1; i < (int) vec.size(); i++) {
        //~ if (vec[i] == '0' && vec[i - 1] == '0') a++;
        //~ else if (vec[i] == '1' && vec[i - 1] == '1') c++;
        //~ else b++;
        //~ }

        //~ cout << a << " " << b << " " << c << "\n";

        for (auto v : vec) cout << v;

        nl;
    }

    return 0;
}
