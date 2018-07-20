/***************************************************
 * Problem name : 10226 Hardwood Species.cpp
 * Problem Link : https://uva.onlinejudge.org/external/102/10226.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : AdHoc
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#include<iomanip>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl cout <<"\n"
//~ #define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    //~ __FastIO;
    ll tc;
    cin >> tc;
    getchar();
    getchar();
    for (ll t = 1; t <= tc; t++) {
        ll n = 0;
        string str;
        map<string, ll>mp;
        while (getline(cin, str)) {
            if ((int)str.size() == 0) break;
            mp[str]++;
            n++;
        }
        map<string, ll>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << " " << fixed << setprecision(4) << (it->second * 100.0) / n << "\n";
        }
        if (t != tc) cout << "\n";
    }
    return 0;
}
