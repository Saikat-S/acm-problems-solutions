/***************************************************
 * Problem name : 10530 Guessing Game.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 18.06.2017
 * Problem Type : AdHoc
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
#define MAX 10
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int n, ans;
    string str;
    vector<int>H, L;
    while (scanf("%d", &n) == 1 && n != 0) {
        while (getline(cin, str)) {
            if (str == "right on") {
                ans = n;
                break;
            }else if (str == "too high") {
                H.push_back(n);
            } else if (str == "too low") {
                L.push_back(n);
            }
            scanf("%d", &n);
        }
        //printf("%d\n", ans);
        bool flag = false;
        int sz = H.size();
        for (int i = 0; i < sz; i++) {
            if (ans >= H[i]) {
                flag = true ;
                break;
            }
        }
        if (flag) printf("Stan is dishonest\n");
        else {
            sz = L.size();
            for (int i = 0; i < sz; i++) {
                if (L[i] >= ans) {
                    flag = true;
                }
            }
            if (flag) printf("Stan is dishonest\n");
            else printf("Stan may be honest\n");

        }
        L.clear();
        H.clear();
    }
    return 0;
}

