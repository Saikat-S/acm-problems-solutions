/***************************************************
 * Problem Name : D. Almost All Divisors.cpp
 * Problem Link : https://codeforces.com/contest/1165/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-16
 * Problem Type : Div 3 - D
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
#define MAX 305
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
vector<int>ar, di;
int n;
void NOD (ll num) {
    int sq = (int) sqrt (num);

    for (int i = 1; i <= sq; i++) {
        if (num % i == 0) {
            if (i != (num / i) ) {
                di.pb (i);
                di.pb (num / i);

            } else {
                di.pb (i);
            }
        }
    }
}

bool fun (ll num) {
    NOD (num);
    sort (all (ar) );
    sort (all (di) );

    for (int i = 0; i < (int) di.size() ; i++) {
        if (ar[i] != di[i]) {
            return false;
        }
    }

    return true;
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        int mx = 0;
        int mn = INF;
        ar.resize (n);

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            mx = max (mx, ar[i]);
            mn = min (mn, ar[i]);
        }

        ll num = (ll) mn * (ll) mx;
        ar.pb (1);
        ar.pb (num);

        if (fun (num) ) cout << num << "\n";
        else cout << -1 << "\n";

        ar.clear(), di.clear();
    }

    return 0;
}
