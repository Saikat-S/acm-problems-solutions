/***************************************************
 * Problem Name : Sundarban Express.cpp
 * Problem Link : https://toph.co/p/sundarban-express
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
int main () {
    __FastIO;
    int tc, n, q;
    cin >> tc;

    while (tc--) {
        cin >> n;
        int sum[n + 3];
        int mx1 = -1, mx2 = -1;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            if (x >= mx1) {
                mx2 = mx1;
                mx1 = x;

            } else if (x > mx2 && x < mx1) {
                mx2 = x;
            }

            sum[i] = mx2;
        }

        cin >> q;

        while (q--) {
            int id;
            cin >> id;
            cout << sum[id] << "\n";
        }
    }

    return 0;
}
