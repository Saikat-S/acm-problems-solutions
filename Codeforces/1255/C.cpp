/***************************************************
 * Problem Name : C.cpp
 * Problem Link : https://codeforces.com/contest/1255/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-11-20
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
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n;
    cin >> n;
    vector<vector<int>>vec (n - 2);
    map<pii, pii>mp;
    map<int, int>cnt;

    for (int i = 0; i < n - 2; i++) {
        vec[i].resize (3);
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
        sort (all (vec[i]) );
        int x = vec[i][0];
        int y = vec[i][1];
        int z = vec[i][2];
        cnt[x]++, cnt[y]++, cnt[z]++;

        if (mp[ {x, y}].first == 0) {
            mp[ {x, y}].first = vec[i][2];

        } else {
            mp[ {x, y}].second = vec[i][2];
        }

        if (mp[ {x, z}].first == 0) {
            mp[ {x, z}].first = vec[i][1];

        } else {
            mp[ {x, z}].second = vec[i][1];
        }

        if (mp[ {y, z}].first == 0) {
            mp[ {y, z}].first = vec[i][0];

        } else {
            mp[ {y, z}].second = vec[i][0];
        }
    }

    vector<int>ans;
    bool vis[MAX];
    SET (vis, false);

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
            ans.pb (i);
            vis[i] = true;
            break;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        int x = vec[i][0];
        int y = vec[i][1];
        int z = vec[i][2];

        if (ans[0] == x) {
            if (cnt[y] == 2) {
                ans.pb (y);
                vis[y] = true;
                break;

            } else {
                ans.pb (z);
                vis[z] = true;
                break;
            }

        } else if (ans[0] == y) {
            if (cnt[x] == 2) {
                ans.pb (x);
                vis[x] = true;
                break;

            } else {
                ans.pb (z);
                vis[z] = true;
                break;
            }

        } else if (ans[0] == z) {
            if (cnt[x] == 2) {
                ans.pb (x);
                vis[x] = true;
                break;

            } else {
                ans.pb (y);
                vis[y] = true;
                break;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        pii p = {min (ans[i - 1], ans[i - 2]), max (ans[i - 1], ans[i - 2]) };
        int x = mp[p].first;
        int y = mp[p].second;

        if (x != 0 && vis[x] == false) {
            ans.pb (x);
            vis[x] = true;

        } else {
            ans.pb (y);
            vis[y] = true;
        }
    }

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }

    nl;
    return 0;
}
