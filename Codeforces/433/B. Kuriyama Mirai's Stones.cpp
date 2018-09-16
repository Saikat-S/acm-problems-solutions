/***************************************************
 * Problem Name : B. Kuriyama Mirai's Stones.cpp
 * Problem Link : http://codeforces.com/contest/433/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-05-27
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int n, q, ar[MAX];
    cin >> n;
    ll sum1[MAX], sum2[MAX];
    sum1[0] = 0;
    for(int i = 1; i<=n; i++) {
        cin >> ar[i];
        sum1[i] = sum1[i-1] + ar[i];
    }
    sort(ar+1, ar+n+1);
    sum2[0] = 0;
    for(int i = 1; i<=n; i++) {
        sum2[i] = sum2[i-1] + ar[i];
    }
    cin >> q;
    for(int i = 1; i<=q; i++) {
        int c, l, r;
        cin >> c>>l>>r;
        if(c == 1) {
            cout << sum1[r] - sum1[l-1]<<"\n";
        }
        else cout << sum2[r] - sum2[l-1]<<"\n";
    }
    return 0;
}
