/***************************************************
 * Problem Name : C. Enlarge GCD.cpp
 * Problem Link : https://codeforces.com/contest/1047/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-28
 * Problem Type : Div 2 - C
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
#define MAX 300005
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
map<int, int>d;
char ar[4005];
vector<int>prime;
void seive (int n) {
    ar[0] = 1, ar[1] = 1;

    for (int i = 4; i < n; i += 2) {
        ar[i] = 1;
    }

    int sq = sqrt (n);

    for (int i = 2; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i + i; j < n; j += i) {
                ar[j] = 1;
            }
        }
    }

    prime.pb (2);

    for (int i = 3; i < n; i++) {
        if (ar[i] == 0) prime.pb (i);
    }
}
int main () {
    __FastIO;
    seive (4005);
    int n;
    int ar[MAX];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int gc = ar[0];

    for (int i = 1; i < n; i++) {
        gc = __gcd (gc, ar[i]);
    }

    for (int i = 0; i < n; i++) {
        ar[i] /= gc;
    }

    for (int i = 0; i < n; i++) {
        int x = ar[i];

        for (int j = 0; j < (int) prime.size() && (prime[j]*prime[j]) <= x; j++) {
            if (x % prime[j] == 0) {
                while (x % prime[j] == 0) {
                    x /= prime[j];
                }

                d[prime[j]]++;
            }
        }

        if (x > 1) d[x]++;
    }

    int ans = INF;

    for (auto it : d) {
        ans = min (ans, n - it.second);
    }

    if (ans == INF) ans = -1;

    cout << ans << "\n";
    return 0;
}
