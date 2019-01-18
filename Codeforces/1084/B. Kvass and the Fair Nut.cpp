/***************************************************
 * Problem Name : B. Kvass and the Fair Nut.cpp
 * Problem Link : https://codeforces.com/contest/1084/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-12-10
 * Problem Type : Div 2 - B
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000009
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
ll N, S;
ll binary (ll total, ll mn) {
    ll low = 0, high = mn;
    ll mid, ans;

    while (high >= low) {
        mid = (high + low) / 2;
        ll val = mid * N;
        val = total - val;

        if (val >= S) {
            low = mid + 1;
            ans = mid;

        } else {
            high = mid - 1;
        }
    }

    return ans;
}
int main () {
    __FastIO;
    cin >> N >> S;
    ll ar[N + 3];
    ll sum = 0;
    ll mn = INF;

    for (int i = 0; i < N; i++) {
        cin >> ar[i];
        sum += ar[i];
        mn = min (mn, ar[i]);
    }

    if (sum < S) {
        cout << "-1\n";

    } else {
        ll ans = binary (sum, mn);
        cout << ans << "\n";
    }

    return 0;
}
