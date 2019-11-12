/***************************************************
 * Problem Name : D. Salary Changing.cpp
 * Problem Link : https://codeforces.com/contest/1251/problem/D
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-10-24
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
vector<pii>vec;
int n;
ll s;
bool cmp (pii a, pii b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}
bool cmp1 (pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

bool check (ll val, int pos) {
    ll sum = 0;
    //~ ll pre = val;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        ll x = vec[i].first;
        ll y = vec[i].second;

        if (i == pos) {
            sum += val;

        } else if (i < pos) {
            if (x > val || val > y) {
                flag = true;
                break;
            }

            sum += x;

        } else {
            if (y < val || val < x) {
                flag = true;
                break;
            }

            sum += val;
        }
    }

    if (sum > s) flag = true;

    if (flag) return false;
    else return true;
}

ll binary (int pos) {
    ll low = vec[pos].first, high = vec[pos].second;
    ll ans = 0LL;

    while (high >= low) {
        ll mid = (high + low) / 2LL;

        if (check (mid, pos) ) {
            ans = mid;
            low = mid + 1;

        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> s;

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            vec.pb ({l, r});
        }

        sort (all (vec), cmp);
        //~ for (int i = 0; i < n; i++) {
        //~ cout << vec[i].first << " " << vec[i].second << "\n";
        //~ }
        ll ans1 = binary (n / 2);
        sort (all (vec), cmp1);
        ll ans2 = binary (n / 2);
        cout << max (ans1, ans2) << "\n";
        //~ cout << ans << "\n";
        vec.clear();
    }

    return 0;
}
