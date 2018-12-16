/***************************************************
 * Problem Name : A.Almost_Prime.cpp
 * Problem Link : https://codeforces.com/contest/26/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-12-06
 * Problem Type : Beta Round - A
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
#define MAX 3005
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
char flag[MAX];
void sieve (int n) {
    prime.pb (2);

    for (int i = 4; i <= n; i += 2) {
        flag[i] = 1;
    }

    int sqrtN = sqrt (n);

    for (int i = 3; i <= sqrtN; i += 2) {
        if (!flag[i]) {
            for (int j = i * i ; j <= n; j += 2 * i) {
                flag[j] = 1;
            }
        }
    }

    for (int i = 3; i <= n; i++) {
        if (!flag[i]) {
            prime.pb (i);
        }
    }
}
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    sieve (n);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 0; j < (int) prime.size(); j++) {
            if (prime[j] > i) break;

            if (i % prime[j] == 0) cnt++;
        }

        if (cnt == 2) ans++;
    }

    cout << ans << "\n";
    return 0;
}
