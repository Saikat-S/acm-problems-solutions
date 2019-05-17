/***************************************************
 * Problem Name : D. Walking Robot.cpp
 * Problem Link : https://codeforces.com/contest/1154/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-22
 * Problem Type : Div 3 - D
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
    int n, a, b, bcap, acap;
    cin >> n >> bcap >> acap;
    int ar[n + 3];

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    a = acap, b = bcap;
    int pos;
    bool f = 0;

    for (int i = 1; i <= n; i++) {
        if (ar[i] == 1) {
            if (b != 0 && a != acap) {
                a = min (acap, a + 1);
                b = max (0, b - 1);

            } else if (a != 0) {
                a = max (0, a - 1);

            } else {
                f = 1;
                pos = i - 1;
                break;
            }

        } else {
            if (a != 0) {
                a = max (0, a - 1);

            } else if (b != 0) {
                b = max (0, b - 1);

            } else {
                f = 1;
                pos = i - 1;
                break;
            }
        }
    }

    if (f == 1) cout << pos << "\n";
    else cout << n << "\n";

    return 0;
}
