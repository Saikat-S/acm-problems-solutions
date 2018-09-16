/***************************************************
 * Problem Name : C.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-05
 * Problem Type :
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
    //~ __FastIO;
    int n;
    int ar[MAX];
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    int mp[MAX], cum[MAX];
    SET (mp, 0);
    cum[n + 1] = 0;
    int cnt = 0;

    for (int i = n; i >= 1; i--) {
        int x = ar[i];

        if (mp[x] == 0) {
            cum[i]  = cum[ i + 1] + 1;
            mp[x] = 1;
            cnt++;

        } else {
            cum[i] = cnt;
        }
    }

    ll sum = 0;
    SET (mp, 0);

    for (int i = 1; i < n; i++) {
        //~ cout << cum[i]<< " ";
        int x = ar[i];

        if (mp[x] == 0) {
            sum += cum[i + 1];
            mp[x] = 1;
        }
    }

    cout << sum << "\n";
    return 0;
}
