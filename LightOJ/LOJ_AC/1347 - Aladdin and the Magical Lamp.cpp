/***************************************************
 * Problem Name : 1347 - Aladdin and the Magical Lamp.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1347
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2020-12-13
 * Problem Type : Suffix Array
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
int ar[MAX];
void count_sort (vector<int> &p, vector<int> &c) {
    int n = (int) p.size();
    vector<int>cnt (n);

    for (auto x : c) {
        cnt[x]++;
    }

    vector<int> p_new (n);
    vector<int>pos (n);
    pos[0] = 0;

    for (int i = 1; i < n; i++) {
        pos[i]  = pos[i - 1] + cnt[i - 1];
    }

    for (auto x : p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }

    p = p_new;
}
int cyclic_sort (string const &str) {
    int n = (int) str.size();
    vector<int>p (n), c (n);
    //~ k = 0;
    vector<pair<char, int>> vec (n);

    for (int i = 0; i < n; i++) {
        vec[i] = {str[i], i};
    }

    sort (all (vec) );

    for (int i = 0; i < n; i++) {
        p[i] = vec[i].second;
    }

    c[p[0]] = 0;

    for (int i =  1; i < n; i++) {
        if (vec[i].first == vec[i - 1].first) {
            c[p[i]] = c[p[i - 1]];

        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    //~ transition part, k -> k+1;
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort (p, c);
        vector<int>c_new (n);
        c_new[p[0]] = 0;

        for (int i =  1; i < n; i++) {
            pair<int, int> pre = {c[p[i - 1]], c[ (p[i - 1] + (1 << k) ) % n]};
            pair<int, int> now =  {c[p[i]], c[ (p[i] + (1 << k) ) % n]};

            if (pre == now) {
                c_new[p[i]] = c_new[p[i - 1]];

            } else {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }

        c = c_new;
    }

    // build the lcp array
    vector<int>lcp (n);
    int k = 0;

    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];
        int j = p[pi - 1];

        // lcp[i] = lcp(s[i..], s[j..])
        while (str[i + k] == str[j + k]) k++;

        lcp[pi] = k;
        k = max (k - 1, 0);
    }

    // Longest Common Substring  of str = s1 + $ + s2 + #;
    int mx = 0;

    //~ cout << str << "  :\n";
    for (int i = 1; i < n - 1 ; i++) {
        //~ cout << ar[p[i]] << " " << lcp[i] << " " << p[i] << " : " << str.substr (p[i], n - p[i]) << "\n";
        int x1 = p[i - 1];
        int x2 = p[i];
        int x3 = p[i + 1];
        set<int>st;
        st.insert (ar[x1]);
        st.insert (ar[x2]);
        st.insert (ar[x3]);

        if ( (int) st.size() == 3) {
            int mn = min (lcp[i], lcp[i + 1]);
            mx = max (mx, mn);
        }
    }

    return mx;
}
int suffix_array (string str) {
    str += '$';
    return cyclic_sort (str);
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    //~ __FileRead;
    //~ __FileWrite;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        string a, b, c;
        cin >> a >> b >> c;
        string str = a + "#" + b + "#" + c;
        int k = 0;

        for (int i = 0; i < (int) str.size(); i++) {
            if (str[i] == '#') {
                ar[i] = k;
                k++;

            } else {
                ar[i] = k;
            }
        }

        ar[ (int) str.size()] = k;
        int res = suffix_array (str);
        cout << "Case " << t << ": ";
        cout << res << "\n";
    }

    return 0;
}
