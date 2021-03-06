/***************************************************
 * Problem name : B.Sherlock_and_his_girlfriend.cpp
 * Problem Link : https://codeforces.com/contest/776/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-12-07
 * Problem type : Div 1,2 - B
 * Author name  : Saikat Sharma
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
vector<int>prime;
char sieve[MAX];
void primeSieve (int n) {
    for (int i = 4; i <= n; i += 2) {
        sieve[i] = 1;
    }

    sieve[0] = 1, sieve[1] = 1;
    prime.pb (2);
    int sqt = sqrt (n);

    for (int i = 3; i <= sqt; i += 2) {
        if (sieve[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) {
                sieve[j] = 1;
            }
        }
    }

    for (int i = 3; i <= n; i += 2) {
        if (sieve[i] == 0) {
            prime.pb (i);
        }
    }
}
int main () {
    //~ __FastIO;
    primeSieve (MAX - 3);
    int n;
    cin >> n;
    int color[MAX];
    SET (color, 0);
    bool flag = false;

    for (int i = 2; i <= n + 1; i++) {
        if (sieve[i] == 0) {
            color[i] = 1;

        } else {
            for (int j = 0; j < (int) prime.size(); j++) {
                if (i % prime[j] == 0) {
                    color[i] = 2;
                    flag = true;
                    break;
                }
            }
        }
    }

    if (!flag) cout << 1 << "\n";
    else cout << 2 << "\n";

    for (int i = 2; i <= n + 1; i++) {
        cout << color[i] << " ";
    }

    nl;
    return 0;
}
