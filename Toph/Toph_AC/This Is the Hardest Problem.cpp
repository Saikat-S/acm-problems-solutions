/***************************************************
 * Problem Name : This Is the Hardest Problem.cpp
 * Problem Link : https://toph.co/p/this-is-the-hardest-problem
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-04-17
 * Problem Type : AdHoc
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
ll fun (ll a, ll b) {
    ll x1 = (a * (a + 1LL) ) / 2LL;
    ll x2 = (b * (b + 1LL) ) / 2LL;
    return (x2 - x1);
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<ll>N;
        ll total = 0;

        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            total += x;

            if (x < 0) {
                N.pb (x);
            }
        }

        sort (all (N) );
        int kk = k - 1;
        ll sum = 0;
        ll mx = total;

        for (int i = 0; i < (int) N.size(); i++) {
            sum += N[i];
            ll tmp  = total - sum;
            tmp = tmp - fun (kk, k);
            mx = max (mx, tmp);

            if (kk > 0) {
                kk--;
            }
        }

        cout << mx << "\n";
    }

    return 0;
}
