/***************************************************
 * Problem name : 1197 - Help Hanzo .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1197
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-10-27
 * Problem Type : Number Theory
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
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 100005
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
ll arr[MAX];
void Seive(ll n) {
    ar[0] = ar[1] = 1;
    for (int i = 4; i <= n; i+=2) ar[i] = 1;
    prime.push_back(2);
    ll sq = sqrt(n);
    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) ar[j] = 1;
        }
    }
    for (int i = 3; i <= n; i++) {
        if (ar[i] == 0) prime.push_back(i);
    }
}
ll segmentedSeive(ll a, ll b) {
    if (a == 1) a++;
    ll sq = sqrt(b);
    for (ll i = 0; i < (ll)prime.size() && prime[i] <= sq; i++) {
        ll p = prime[i];
        ll j = p * p;
        if (j < a) {
            j = (((a + p - 1) / p) * p);

        }
        for(; j<=b; j+=p){
            arr[j-a] = 1;
        }
    }
    ll cnt = 0;
    for(ll i = a; i<=b; i++){
        if(arr[i - a] == 0) cnt++;
    }
    return cnt;
}
int main () {
    Seive(MAX);
    int tc;
    ll a, b;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &a, &b);
        SET(arr);
        printf("Case %d: %lld\n", t, segmentedSeive(a, b));

    }
    return 0;
}

