/***************************************************
 * Problem Name : B. Taxi.cpp
 * Problem Link : http://codeforces.com/contest/158/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-17
 * Problem Type : VK Cup 2012 - B
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
int main () {
    __FastIO;
    int n;
    cin >> n;
    int ar[5];
    int sum = 0;
    SET (ar, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ar[x]++;
    }

    if (ar[4] != 0) {
        sum += ar[4];
    }

    if (ar[3] != 0) {
        if (ar[3] >= ar[1]) {
            sum += ar[3];
            ar[1] = 0;

        } else {
            sum += ar[3];
            ar[1] -= ar[3];
        }
    }

    if (ar[2] != 0) {
        sum += ar[2] / 2;
        int x = ar[2] % 2;

        if (x == 1) {
            sum += 1;
            ar[1] -= 2;

            if (ar[1] < 0) ar[1] = 0;
        }
    }

    if (ar[1] != 0) {
        double x = (double) ar[1] / 4.0;
        int xx = ceil (x);
        sum += xx;
    }

    cout << sum << "\n";
    return 0;
}
