/***************************************************
 * Problem Name : B. Average Superhero Gang Power.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-02-03
 * Problem Type :
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
int main () {
    //~ __FastIO;
    ll n, k, m;
    ll ar[MAX];
    scanf ("%lld %lld %lld", &n, &k, &m);

    for (int i = 1; i <= n; i++) {
        scanf ("%lld", &ar[i]);
    }

    sort (ar + 1, ar + n + 1);
    ll sum[MAX];
    sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] +  ar[i];
    }

    double mx = 0.0;

    for (int i = 0; i < n; i++) {
        ll xx = n - i;
        ll op = m - i;

        if (xx * k <= op) {
            double ans = (double) sum[n] - (double) sum[i];
            ans = ans + (xx * 1.0 * k);
            double tmp = ans / (double) xx;
            mx = max (mx, tmp);

        } else {
            double ans = (double) sum[n] - (double) sum[i];
            ans = ans + (op * 1.0);
            double tmp = ans / (double) xx;
            mx = max (mx, tmp);
        }
    }

    printf ("%.15lf\n", mx);
    return 0;
}
