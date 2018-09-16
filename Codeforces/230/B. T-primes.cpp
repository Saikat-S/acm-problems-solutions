/***************************************************
 * Problem Name : B. T-primes.cpp
 * Problem Link : http://codeforces.com/contest/230/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-17
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
bool prime[1000006];
void seive() {
    int i, j;
    prime[1] = 1;

    for (i = 2; i <= 1000; i++) {
        if (prime[i]) continue;

        for (j = i + i; j <= 1000000; j += i) {
            prime[j] = 1;
        }
    }
}
int main () {
    __FastIO;
    seive();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        ll sq = (ll) sqrt (x);

        if (sq * sq == x && (prime[sq] == 0) ) {
            cout << "YES\n";

        } else cout << "NO\n";
    }

    return 0;
}
