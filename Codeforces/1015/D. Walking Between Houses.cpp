/***************************************************
 * Problem Name : D. Walking Between Houses.cpp
 * Problem Link : http://codeforces.com/contest/1015/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-31
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
#define pb push_back
#define MAX 100005
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
ll n, k, s;
//~ bool flag;
vector<ll>ans;
ll fun (ll pos, ll sum) {
    //~ cout << pos <<" "<< sum << " "<< cnt << "\n";
    if (pos  - sum > 0) {
        //~ if (sum == s) {
        //~ flag = 1;
        return pos - sum;
        //~ } else return 0;

    } else {
        return pos + sum;
    }

    //~ bool chk;
    //~ ll i = 1;
    //~ for (i = n; i >= 1; i--) {
    //~ if (i != pos) {
    //~ chk = fun (i, sum += abs ( pos - i), cnt + 1);
    //~ if(chk == 1 ) break;
    //~ cout << chk<<"\n";
    //~ }
    //~ }
    //~ if (chk == 1) ans.pb (i);
}
int main () {
    //~ __FastIO;
    //~ ll n, k, s;
    cin >> n >> k >> s;

    if (k > s || k * (n - 1) < s) {
        cout << "NO\n";
        return 0;
    }

    ll pos = 1;

    while (k > 0) {
        ll x = min (n - 1, s - (k - 1) );
        pos = fun (pos, x);
        ans.pb (pos);
        s -= x;
        k--;
    }

    cout << "YES\n";

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }

    nl;
    return 0;
}
