/***************************************************
 * Problem Name : B. All the Vowels Please.cpp
 * Problem Link : https://codeforces.com/contest/1166/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-29
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
#define MAX 100005
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
int main () {
    __FastIO;
    int k;
    cin >> k;
    int m = 0, n = 0;

    for (int i = 5; i <= k; i++) {
        if (k % i == 0 && (k / i) >= 5) {
            m = i;
            n = k / i;
        }
    }

    if (m == 0) {
        cout << -1 << "\n";
        exit (0);
    }

    string vol[5];
    vol[0] = "aeiou";
    vol[1] = "eioua";
    vol[2] = "iouae";
    vol[3] = "ouaei";
    vol[4] = "uaeio";

    for (int l = 0, kk = 0; l < m; l++) {
        if (kk == 5) kk = 0;

        for (int i = 0, j = 0; i < n; i++) {
            if (j == (int) vol[kk].size() ) j = 0;

            cout << vol[kk][j++];
        }

        kk++;
    }

    nl;
    return 0;
}
