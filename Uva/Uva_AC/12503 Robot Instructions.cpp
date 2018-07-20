/***************************************************
 * Problem name : 12503 Robot Instructions.cpp
 * Problem Link : https://uva.onlinejudge.org/external/125/12503.pdf
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
    int tc, n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        map<int, string>mp;
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            if (str == "LEFT") {
                mp[i] = "LEFT";
                pos = pos - 1;

            } else if (str == "RIGHT") {
                mp[i] = "RIGHT";
                pos = pos + 1;
            } else {
                int x;
                cin >> str >> x;
                string s = mp[x];
                if (s == "LEFT") {
                    pos = pos - 1;
                    mp[i] = "LEFT";
                } else {
                    mp[i] = "RIGHT";
                    pos = pos + 1;
                }
            }
        }
        printf("%d\n", pos);
    }

    return 0;
}
