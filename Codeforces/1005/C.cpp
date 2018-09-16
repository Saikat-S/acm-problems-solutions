/***************************************************
 * Problem Name : C.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-09
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
#define MAX 120005
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
    ll n;
    ll ar[MAX];
    cin >> n;
    map<ll, int>mp;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
    }

    vector<ll>v;

    for (int i = 0; i < 32; i++) {
        v.pb ( (1 << i) );
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        bool flag = 1;

        for (int j = 0; j < (int) v.size(); j++) {
            if (ar[i] < v[j]) {
                ll x = v[j] - ar[i];

                if (mp[x] > 1) {
                    flag = 0;
                    break;

                } else if (mp[x] == 1 && x != ar[i]) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
