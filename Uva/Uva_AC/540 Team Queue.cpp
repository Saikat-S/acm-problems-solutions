/***************************************************
 * Problem name : 540 Team Queue.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/540.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : AdHoc(STL)
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
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 1005
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int t;
    int tc = 1;
    while (scanf("%d", &t) == 1 && t != 0) {
        vector<ll>ar[MAX];
        map<ll, ll>mp;
        for (int i  = 1; i <= t; i++) {
            ll x;
            scanf("%lld", &x);
            for (int j = 1; j <= x; j++) {
                ll value;
                scanf("%lld", &value);
                mp[value] = i;
            }
        }
        string str;
        ll chk[MAX];
        SET(chk, 0);
        vector<ll>team, ans;
        while (cin >> str) {
            if (str == "STOP") break;
            if (str == "ENQUEUE") {
                ll teamMember;
                scanf("%lld", &teamMember);
                if (chk[mp[teamMember]] == 0) {
                    team.pb(mp[teamMember]);
                    chk[mp[teamMember]] = 1;
                }
                ar[mp[teamMember]].pb(teamMember);
            } else if (str == "DEQUEUE") {
                for (int i = 0; i < (int)team.size(); i++) {
                    ll x = team[i];
                    if ((int)ar[x].size() == 0) {
                        continue;
                    }
                    ans.pb(ar[x][0]);
                    ar[x].erase (ar[x].begin() + 0);
                    if ((int)ar[x].size() == 0) {
                        team.erase (team.begin() + i);
                        chk[x] = 0;
                    }
                    break;
                }
            }
        }
        printf("Scenario #%d\n", tc++);
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld\n", ans[i]);
        }
        nl;
    }
    return 0;
}
