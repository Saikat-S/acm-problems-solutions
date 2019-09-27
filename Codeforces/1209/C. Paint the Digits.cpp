/***************************************************
 * Problem Name : C. Paint the Digits.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-09-14
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
#define MAX 200005
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
struct st {
    int d, pos;
};

bool cmp (st a, st b) {
    if (a.d == b.d) return a.pos < b.pos;
    else return a.d < b.d;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n;
    string str;
    cin >> tc;

    while (tc--) {
        cin >> n;
        cin >> str;
        st ar[MAX];
        bool col[MAX];
        SET (col, false);

        for (int i = 0; i < n; i++) {
            int d = str[i] - '0';
            ar[i].d = d;
            ar[i].pos = i;
        }

        sort (ar, ar + n, cmp);
        int id = ar[0].pos;
        col[id] = true;
        int ck = -1;

        for (int i = 1; i < n; i++) {
            int x = ar[i].pos;

            if (ck == -1) {
                if (x > id) {
                    col[x] = true;
                    id = x;

                } else {
                    ck = ar[i].d;
                }

            } else {
                if (x > id && ar[i].d <= ck) {
                    col[x] = true;
                    id = x;
                }
            }
        }

        bool flag = false;
        int last =  -1;

        for (int i = 0; i < n; i++) {
            if (col[i] == true) {
                if (last == -1) {
                    last = i;

                } else {
                    int d1 = str[last] - '0';
                    int d2 = str[i] - '0';

                    if (d1 > d2) {
                        flag = true;
                        break;

                    } else {
                        last = i;
                    }
                }
            }
        }

        last = -1;

        for (int i = 0; i < n; i++) {
            if (col[i] == false) {
                if (last == -1) {
                    last = i;

                } else {
                    int d1 = str[last] - '0';
                    int d2 = str[i] - '0';

                    if (d1 > d2) {
                        flag = true;
                        break;

                    } else {
                        last = i;
                    }
                }
            }
        }

        if (flag) {
            cout << "-\n";

        } else {
            for (int i = 0; i < n; i++) {
                if (col[i] == true) cout << 1;
                else cout << 2;
            }

            nl;
        }
    }

    return 0;
}
