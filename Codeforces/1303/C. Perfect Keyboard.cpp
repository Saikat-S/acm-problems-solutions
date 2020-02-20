/***************************************************
 * Problem Name : C. Perfect Keyboard.cpp
 * Problem Link : https://codeforces.com/contest/1303/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-02-12
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
vector<int>adj[30];
bool vis[30];
vector<int>path;
bool dfs (int u, int p) {
    vis[u] = true;
    path.pb (u);

    for (auto v : adj[u]) {
        if (v == p) continue;

        if (vis[v] == true) {
            return true;

        } else {
            return dfs (v, u);
        }
    }

    return false;
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        string str;
        cin >> str;
        int n = (int) str.size();
        char ch = 'a';
        map<int, char>mp;

        for (int i = 1; i <= 26; i++) {
            mp[i] = ch++;
        }

        if (n == 1) {
            cout << "YES\n";

            for (int i = 1; i <= 26; i++) {
                cout << mp[i];
            }

            nl;
            continue;
        }

        int ar[30][30];
        SET (ar, 0);

        for (int i = 1; i < n; i++) {
            int x1 = (str[i - 1] - 'a') + 1;
            int x2 = (str[i] - 'a') + 1;

            if (x1 == x2) continue;

            if (ar[x1][x2] != 1) {
                adj[x1].pb (x2);
                ar[x1][x2] = 1;
            }

            if (ar[x2][x1] != 1) {
                adj[x2].pb (x1);;
                ar[x2][x1] = 1;
            }
        }

        bool flag = false;

        for (int i = 1; i <= 26; i++) {
            if ( (int) adj[i].size() > 2) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "NO\n";

        } else {
            int nod  = -1;

            for (int i = 1; i <= 26; i++) {
                if (adj[i].size() == 1) {
                    nod = i;
                    break;
                }
            }

            if (nod == -1) {
                cout << "NO\n";

            } else {
                SET (vis, false);
                path.clear();

                if (dfs (nod, -1) ) {
                    cout << "NO\n";

                } else {
                    cout << "YES\n";
                    map<int, bool>MM;

                    for (int i = 0; i < (int) path.size(); i++) {
                        int v = path[i];
                        cout << mp[v];
                        MM[v] = true;
                    }

                    for (int i = 1; i <= 26; i++) {
                        if (MM[i] == false) {
                            cout << mp[i];
                        }
                    }

                    nl;
                }
            }
        }

        for (int i = 1; i < 30; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
