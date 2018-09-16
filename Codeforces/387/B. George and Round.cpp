/***************************************************
 * Problem Name : B. George and Round.cpp
 * Problem Link : http://codeforces.com/contest/387/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-12
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
#define MAX 1000005
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
int a[MAX], b[MAX];
int binary (int n, int value) {
    int low = 0, high = n - 1, ans = -1;

    while (high >= low) {
        int mid = (high + low) / 2;

        if (b[mid] == value) {
            ans = mid;
            high = mid - 1;

        } else if (b[mid] > value) {
            high  = mid - 1;

        } else low = mid + 1;
    }

    if (ans == -1) {
        ans = high + 1;
    }

    return ans;
}
int main () {
    __FastIO;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n ; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort (a, a + n);
    sort (b, b + m );
    int cnt = 0;

    for (int i = n - 1; i >= 0 ; i--) {
        int x = a[i];
        int low = m - binary (m, x);

        if (low == 0 || (low + cnt) < (n - i) ) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
