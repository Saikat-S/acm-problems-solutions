/***************************************************
 * Problem name : 119 - Greedy Gift Givers.cpp
 * Problem Link : https://uva.onlinejudge.org/external/1/119.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-23
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
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 11
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
map<string, int>mp;
int main () {
    int n,t = 0;
    string str[MAX];
    while (scanf("%d", &n) == 1) {
        getchar();
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        for (int i = 1; i <= n; i++) {
            string s, ss;
            int t_gift, gift, fnd;
            cin >> s >> t_gift >> fnd;
            if (fnd != 0) {
                gift = t_gift / fnd;
                mp[s] -= t_gift;
                getchar();
                for (int j = 1; j <= fnd; j++) {
                    cin >> ss;
                    mp[ss] += gift;
                }
                mp[s] += (t_gift - (gift * fnd));
            }
        }
        if(t!=0) nl;
        for (int i = 0; i < n; i++) {
            cout << str[i] << " " << mp[str[i]] << "\n";
        }
        t++;
        mp.clear();
    }
    return 0;
}

