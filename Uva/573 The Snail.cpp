/***************************************************
 * Problem name : 573 The Snail.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/573.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-25
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
#define MAX 100000
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
    double H, U, D, F;
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F) == 4) {
        if (H == 0) break;
        double iH = 0, dC = U, hAc;
        int ans, flag;
        double f = dC * (F / 100.0);
        //~ printf("%lf\n", f);
        for (int i = 1; ; i++) {
            hAc = iH + dC;
            //~ printf("%lf ,  %lf ,  %lf , %lf\n", iH,dC,hAc, D);
            if (hAc > H) {
                flag = 0;
                ans = i;
                break;
            }
            iH = hAc - D;
            if (iH < 0) {
                ans = i;
                flag = 1;
                break;
            }
            dC = dC - f;
            if (dC <= 0) {
                for(int j = i; ;j++){
                    iH-=D;
                    if(iH<0){
                        flag = 1;
                        ans = j+1;
                        break;
                    }
                }
                break;
            }
        }
        //~ printf("%lf ,  %lf ,  %lf , %lf\n", iH,dC,hAc, D);
        if (flag) {
            printf("failure on day %d\n", ans);
        } else {
            printf("success on day %d\n", ans);
        }
    }
    return 0;
}
