/***************************************************
 * Problem name : 1259 - Goldbach`s Conjecture .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1259
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-11-02
 * Problem Type : NT
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 10000007
//~ #define MAX 100
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
vector<ll>prime;
char ar[MAX];
void Seive(ll MX) {
    ar[0] = ar[1] = 1;
    for (ll i = 4; i <= MX; i += 2) {
        ar[i] = 1;
    }
    ll sq = sqrt(MX);
    for (ll i = 3; i <= sq; i += 2) {
        if (ar[i] == 0) {
            for (ll j = i * i; j <= MX; j += 2 * i) {
                ar[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for (ll i = 3; i <= MX; i++) {
        if (ar[i] == 0) prime.push_back(i);
    }
}
int main () {
    Seive(MAX);
    //~ for (ll i = 0; i <(ll)prime.size(); i++) {
     //~ cout << prime[i]<< ' ';
    //~ }
    int tc;
    ll n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld", &n);
        ll cnt = 0;
        ll sq = n/2;
        for (ll i = 0; i <= (ll)prime.size() && prime[i] <= sq; i++) {
            if (ar[n - prime[i]] == 0) {
                //~ printf("%lld ", prime[i]);
                cnt++;
            }
        }
        printf("Case %d: %lld\n", t, cnt);
    }
    return 0;
}

