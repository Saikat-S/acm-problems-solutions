/***************************************************
 * Problem name : 11362 Phone List.cpp
 * Problem Link : https://uva.onlinejudge.org/external/113/11362.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-27
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
#define MAX 10003
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
    int tc, n;
    //~ string str[MAX];
    //~ map<string, bool>mp;
    vector<string>V;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            //~ mp[str] = 1;
            V.push_back(str);
        }
        sort(V.begin(), V.end());
        //~ for(int i = 0 ; i<n; i++){
        //~ cout << V[i] << " ";
        //~ }
        //~ nl;
        int flag = 0;
        for (int i = 0; i < n - 1; i++) {
            //~ for (int j = i + 1; j < n; j++) {
            if (V[i] == V[i + 1].substr(0, V[i].size())) {
                flag = 1;
                break;
            }
            //~ }
            //~ if (flag) break;
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
        V.clear();
    }
    return 0;
}
