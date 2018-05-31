/***************************************************
 * Problem Name : A - Appearance Count.cpp
 * Problem Link : https://www.codechef.com/problems/ZUBAPCNT
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-05-25
 * Problem Type : Easy
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
#define pb push_back
#define MAX 100005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
ll BigMod(ll a, ll b, ll m) {
    if (b == 0) return 1 % m;
    ll x = BigMod(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2 == 1)
        x = (x * a) % m;
    return x;
}
int main () {
    ll tc, n,m;
    string str;
    cin >> tc;
    for(ll t = 1; t<=tc; t++) {
        cin >> n >> m;
        cout << "Case "<<t<<":\n";
        for(ll q = 1; q<=m; q++) {
            cin >> str;
            ll len = (ll)str.size();
            ll b = n - len;
            ll xx = (n - len + 1);
            if( xx <= 0 ) {
                cout << "0" << endl ;
            }
            else {
                ll x = BigMod(26,b,MOD);
                ll ans = (x * xx)%MOD;
                cout << ans<<"\n";
            }
        }
    }
    return 0;
}
