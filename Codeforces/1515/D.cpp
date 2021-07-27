/***************************************************
 * Problem Name : D.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2021-05-02
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
#include <chrono>
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
#define debugP cout <<"######\n"
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
#define un_map unordered_map
#define un_set unordered_set
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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out (Head H, Tail... T) {
    cerr << " " << to_string (H);
    debug_out (T...);
}
#define debug(...) cerr << "Line : " << __LINE__ <<" [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
struct custom_hash {
    static uint64_t splitmix64 (uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30) ) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27) ) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator() (uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                        chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64 (x + FIXED_RANDOM);
    }
};
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
        int n, l, r;
        cin >> n >> l >> r;
        multiset<int>left, right;
        int N = n;

        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;

            if (i <= l) {
                left.insert (x);

            } else {
                auto it = left.find (x);

                if (it != left.end()) {
                    left.erase (it);
                    n -= 2;
                    l--, r--;

                } else {
                    right.insert (x);
                }
            }
        }

        int cost = 0;
        int x = n / 2;

        if (l > x) {
            int need = l - x;
            //~ cout << "left : " << need << '\n';
            multiset<int>newl;

            for (auto it : left) {
                if (need == 0) {
                    newl.insert (it);

                } else {
                    int val = it;
                    auto it1 = newl.find (val);

                    if ( it1 != newl.end()) {
                        need--;
                        cost++;
                        newl.erase (it1);

                    } else {
                        newl.insert (it);
                    }
                }
            }

            //~ cout << need << "\n";

            for (int i = 0; i < need; i++) {
                auto itP = newl.begin();
                right.insert (*itP);
                newl.erase (itP);
                cost++;
            }

            // com
            for (auto it : newl) {
                auto it1 = right.find (it);

                if (it1 != right.end()) {
                    right.erase (it1);
                }
            }

            cost += (int)right.size();

        } else if (r > x) {
            // if right ++
            int need = r - x;
            //~ cout << "right : " << need << '\n';
            multiset<int>newr;

            for (auto it : right) {
                if (need == 0) {
                    newr.insert (it);

                } else {
                    int val = it;
                    auto it1 = newr.find (val);

                    if ( it1 != newr.end()) {
                        need--;
                        cost++;
                        newr.erase (it1);

                    } else {
                        newr.insert (it);
                    }
                }
            }

            for (int i = 0; i < need; i++) {
                auto itP = newr.begin();
                left.insert (*itP);
                newr.erase (itP);
                cost++;
            }

            // com
            for (auto it : left) {
                auto it1 = newr.find (it);

                if (it1 != newr.end()) {
                    newr.erase (it1);
                }
            }

            cost += (int)newr.size();

        } else {
            for (auto it : left) {
                auto it1 = right.find (it);

                if (it1 != right.end()) {
                    right.erase (it1);
                }
            }

            cost += (int)right.size();
        }

        cout << cost << "\n";
    }

    return 0;
}
