/***************************************************
 * Problem Name : A. Cinema Line.cpp
 * Problem Link : https://codeforces.com/contest/349/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-30
 * Problem Type : Div 2 - A
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
int main () {
    __FastIO;
    int n, a25 = 0, a50 = 0;
    cin >> n;
    int flag = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 25) {
            a25++;

        } else if (x == 50) {
            if (a25 == 0) {
                flag = 1;

            } else {
                a25--;
                a50++;
            }

        } else if (x == 100) {
            if (a50 != 0) {
                if (a25 == 0) {
                    flag = 1;

                } else {
                    a25--;
                    a50--;
                }

            } else {
                if (a25 < 3) {
                    flag = 1;

                } else {
                    a25 -= 3;
                }
            }
        }
    }

    if (flag) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
