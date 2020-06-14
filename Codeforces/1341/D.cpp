/***************************************************
 * Problem Name : D.cpp
 * Problem Link : https://codeforces.com/contest/1341/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-04-23
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
#define MAX 2005
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
vector<string>vec;
map<int, string>mp;
int dp[MAX][MAX];
int n, k;

void pre() {
    mp[0] = "1110111";
    mp[1] = "0010010";
    mp[2] = "1011101";
    mp[3] = "1011011";
    mp[4] = "0111010";
    mp[5] = "1101011";
    mp[6] = "1101111";
    mp[7] = "1010010";
    mp[8] = "1111111";
    mp[9] = "1111011";
}

int solve (int pos, int val) {
    string s = vec[pos];
    string str = mp[val];
    int cnt = 0;

    for (int i = 0; i < 7; i++) {
        if (s[i] != str[i]) {
            if (s[i] == '0') cnt++;
            else {
                return -1;
            }
        }
    }

    return cnt;
}


int fun (int pos, int kk) {
    if (pos >= n) {
        if (kk == 0) {
            return 1;

        } else {
            return 0;
        }
    }

    int &res = dp[pos][kk];

    if (res != -1) return res;

    int mx = -1;

    for (int i = 9; i >= 0; i--) {
        int cnt = solve (pos, i);

        if (cnt != -1 && cnt <= kk) {
            int f = fun (pos + 1, kk - cnt);

            if (f != 0) {
                mx = max (i, mx);
            }
        }
    }

    if (mx == -1) res = 0;
    else res = 1;

    return res;
}


void path (int pos, int kk) {
    if (pos >= n) {
        return;
    }

    for (int i = 9; i >= 0; i--) {
        int cnt = solve (pos, i);

        if (cnt != -1 && cnt <= kk) {
            int f = fun (pos + 1, kk - cnt);

            if (f != 0) {
                cout << i;
                path (pos + 1, kk - cnt);
                break;
            }
        }
    }
}


int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    pre();
    cin >> n >> k;
    vec.resize (n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    SET (dp, -1);
    int f = fun (0, k);

    if (f == 0) {
        cout << -1 << "\n";

    } else {
        path (0, k);
        nl;
    }

    return 0;
}
