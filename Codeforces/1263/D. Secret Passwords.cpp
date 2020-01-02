/***************************************************
 * Problem Name : D. Secret Passwords.cpp
 * Problem Link : https://codeforces.com/contest/1263/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-11-29
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
#define pii pair<int,string>
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
int par[29];

void init() {
    for (int i = 1; i < 29; i++) {
        par[i] = i;
    }
}

int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}

void makeSet (int x, int y) {
    int u = find (x);
    int v = find (y);

    if (u != v) {
        par[v] = u;
    }
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    init();
    int n;
    cin >> n;
    vector<string>vec;
    map<char, int>mp;
    int k = 1;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (char ch : str) {
            if (!mp[ch]) mp[ch] = k++;
        }

        for (int j = 1; j < SZ (str); j++) {
            makeSet (mp[str[0]], mp[str[j]]);
        }

        vec.pb (str);
    }

    int cnt = 0;
    map<int, bool>chk;

    for (int i = 1; i < k; i++) {
        if (!chk[find (i)]) {
            chk[find (i)] = true;
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
