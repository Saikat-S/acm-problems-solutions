/***************************************************
 * Problem Name : A. Fingerprints.cpp
 * Problem Link : http://codeforces.com/contest/994/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-06-23
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
    int n, m;
    cin >> n >> m;
    int ar[13];
    int mp[13];
    SET (mp, 0);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp[x] = 1;
    }

    vector<int>v;

    for (int i = 0; i < n; i++) {
        if (mp[ar[i]] == 1) {
            v.pb (ar[i]);
        }
    }

    if ( (int) v.size() == 0) nl
        else {
            for (int i = 0; i < (int) v.size(); i++) {
                cout << v[i] << " ";
            }

            nl;
        }

    return 0;
}
