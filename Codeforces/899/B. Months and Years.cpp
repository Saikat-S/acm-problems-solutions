/***************************************************
 * Problem Name : B. Months and Years.cpp
 * Problem Link : http://codeforces.com/contest/899/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-28
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int ar[27];
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check (int x, int n) {
    int j = 1;
    int i = x;
    int cnt = 0;

    while (1) {
        if (j == n + 1) break;

        if ( i == 13) i = 1;

        if (ar[j] == 28 || ar[j] == 29) {
            if (ar[j] == 29) cnt++;

            if (month[i] != 28 || cnt >= 2) return false;

        } else if (ar[j] != month[i]) return false;

        i++, j++;
    }

    return true;
}
int main () {
    __FastIO;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    int flag = 0;

    for (int i = 1; i <= 12; i++) {
        if (ar[1] == 28 || ar[1] == 29) {
            if (month[i] == 28) {
                if (check (i, n) ) {
                    flag = 1;
                    break;
                }
            }

        } else if (ar[1] == month[i]) {
            if (check (i, n) ) {
                flag = 1;
                break;
            }
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
