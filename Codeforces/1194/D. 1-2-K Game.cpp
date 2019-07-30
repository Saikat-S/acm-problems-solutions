/***************************************************
 * Problem Name : D. 1-2-K Game.cpp
 * Problem Link : https://codeforces.com/contest/1194/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-15
 * Problem Type : Edu R - D(pattern)
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
//~ generate pattern W = Alice Win , L = Bob Win
//~ void solve (int n, int k) {
//~ int *ar = (int *) calloc (n + 1, sizeof (int) );
//~ ar[0] = -1;
//~ ar[1] = 1;
//~ ar[2] = 1;

//~ for (int i = 3; i <= n; i++) {
//~ if (ar[i - 1] == -1 || ar[i - 2] == -1 || (i >= k && ar[i - k] == -1) ) {
//~ ar[i] = 1;

//~ } else {
//~ ar[i] = -1;
//~ }
//~ }

//~ for (int i = 0; i <= n; i++) {
//~ if (ar[i] == 1) cout << "W  ";
//~ else cout << "L  ";
//~ }

//~ nl;

//~ for (int i = 0; i < n; i++) {
//~ if (ar[i] == -1) cout << i << ' ';
//~ else cout << "  ";
//~ }

//~ nl;
//~ }


int main () {
    __FastIO;
    int tc;
    int n, k;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;

        //~ solve (n, k);
        if (k == 3 || n == 0) {
            if (n % 4 == 0) {
                cout << "Bob\n";

            } else {
                cout << "Alice\n";
            }

        } else if (k % 3 != 0) {
            if (n % 3 == 0 && n >= 2) {
                cout << "Bob\n";

            } else {
                cout << "Alice\n";
            }

        } else {
            int x = n % (k + 1);

            if (x == k) {
                cout << "Alice\n";

            } else {
                if (x % 3 == 0) {
                    cout << "Bob\n";

                } else {
                    cout << "Alice\n";
                }
            }
        }
    }

    return 0;
}

