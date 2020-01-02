/***************************************************
 * Problem Name : C. Friends and Gifts.cpp
 * Problem Link : https://codeforces.com/contest/1283/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-12-30
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
int par[MAX];
int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}
void makeSet (int x, int y) {
    int u = find (x);
    int v = find (y);

    if (u != v) {
        par[u] = v;
    }
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n;
    pii ar[MAX];
    cin >> n;

    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (x != 0) {
            ar[i].second = x;
            ar[x].first = i;
            makeSet (x, i);
        }
    }

    set<int>D, N, A;

    for (int i = 1 ; i <= n; i++) {
        int x =  ar[i].first;
        int y =  ar[i].second;

        if (x == 0 && y == 0) {
            A.insert (i);

        } else if (x == 0) {
            N.insert (i);

        } else if (y == 0) {
            D.insert (i);
        }
    }

    if ( (int) A.size() > 1) {
        for (auto it = A.begin(); it != A.end(); it++) {
            auto tmp = it;
            int x = *tmp;

            if (tmp == A.begin() ) {
                N.insert (x);
            }

            tmp++;

            if (tmp == A.end() ) {
                D.insert (x);
                break;
            }

            int y = *tmp;
            ar[x].second = y;
            ar[y].first = x;
            makeSet (x, y);
        }

    } else if ( (int) A.size() == 1) {
        auto it = A.begin();
        auto it1 = N.begin();
        int x = *it;
        int y = *it1;
        N.erase (it1);
        ar[y].first = x;
        ar[x].second = y;
        N.insert (x);
    }

    while (!N.empty() ) {
        int x = *N.begin();

        for (auto itD = D.begin(); itD != D.end(); itD++) {
            int y = *itD;

            if ( (int) D.size() == 1) {
                ar[x].first = y;
                ar[y].second = x;
                makeSet (x, y);
                N.erase (N.find (x) );
                D.erase (D.find (y) );
                break;

            } else {
                if (find (x) != find (y) ) {
                    ar[x].first = y;
                    ar[y].second = x;
                    makeSet (x, y);
                    N.erase (N.find (x) );
                    D.erase (D.find (y) );
                    break;
                }
            }
        }

        if (N.empty() ) break;
    }

    for (int i = 1; i <= n; i++) {
        cout << ar[i].second << " ";
    }

    nl;
    return 0;
}
