/***************************************************
 * Problem Name : 1141 - Number Transformation.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1141
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-01
 * Problem Type : Graph
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
#define pii pair<ll,ll>
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
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 1005
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
vector <int> prime, fact[MAX];

char ar[MAX];
int dis[MAX];

void sieve (int n) {
    ar[0] = ar[1] = 1;

    for (int i = 4; i <= n; i += 2) ar[i] = 1;

    prime.push_back (2);
    int sq = sqrt (n);

    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) ar[j] = 1;
        }
    }

    for (int i = 3; i <= n; i++) {
        if (ar[i] == 0) prime.push_back (i);
    }
}
void factorize ( int n ) {
    int sqrtn = sqrt ( n );
    int num = n;

    for ( int i = 0; i < (int) prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
            }

            fact[num].pb (prime[i]);
            sqrtn = sqrt ( n );
        }
    }

    if ( n != 1 ) {
        fact[num].pb (n);
    }

    if (n == num) {
        fact[num].clear();
    }
}

int bfs (int s, int d) {
    SET (dis, -1);
    queue<int>q;
    q.push (s);
    dis[s] = 0;

    while (!q.empty() ) {
        int u = q.front();
        q.pop();

        for (auto x : fact[u]) {
            int v = u + x;

            if (v <= d && dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push (v);

                if (v == d) {
                    return dis[v];
                }
            }
        }
    }

    return dis[d];
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    sieve (MAX - 3);

    for (int i = 1; i < MAX; i++) {
        factorize (i);
    }

    int tc, A, B;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> A >> B;
        factorize (A);
        int ans = bfs (A, B);
        cout << "Case " << t << ": ";
        cout << ans << "\n";
    }

    return 0;
}
