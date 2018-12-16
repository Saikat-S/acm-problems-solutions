/***************************************************
 * Problem Name : TDPRIMES-Printing_some_primes.cpp
 * Problem Link : https://www.spoj.com/problems/TDPRIMES/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-12-06
 * Problem Type : Number Theory (sieve)
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
#define max 100000000
#define lmt 10000

unsigned flag[max / 64];
int prime[max], total;

#define chkC(n) (flag[n>>6] & (1<<((n>>1) & 31)))
#define setC(n) (flag[n>>6] |= (1 <<((n>>1) & 31)))

void sieve() {
    unsigned i, j, k;
    flag[0] |= 0;

    for (i = 3; i < lmt; i += 2) {
        if (!chkC (i) ) {
            for (j = i * i, k = i << 1; j < max; j += k) {
                setC (j);
            }
        }
    }

    prime[ (j = 0)++] = 2;

    for (i = 3; i < max; i += 2) {
        if (!chkC (i) ) {
            prime[j++] = i;
        }
    }

    total = j - 1;
}
int main () {
    __FastIO;
    sieve();
    int i = 0;

    while (total > i) {
        cout << prime[i] << "\n";
        i += 100;
    }

    return 0;
}
