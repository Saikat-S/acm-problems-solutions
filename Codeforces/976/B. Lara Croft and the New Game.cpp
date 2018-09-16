/***************************************************
 * Problem name : B. Lara Croft and the New Game.cpp
 * OJ           :
 * Verdict      : Trying
 * Date         : 2018-04-30
 * Problem Type :
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
/************************************ Code Start Here ******************************************************/
int main () {
    ll  n, m, k;
    while (scanf("%lld %lld %lld", &n, &m, &k) == 3) {
        //~ ll mm = m - 2;
        if (k < n) {
            printf("%lld 1\n", k + 1);
        } else {
            //~ for(ll i = n*m-1 ; )
            ll X = (k-n);

            ll x = X/(m-1);
            ll row =  n - x;
            ll col;
            //~ ll xx = 0, yy = mm
            
            ll xx = X%(m-1);
            
            if(row%2 == 0){
                col = xx+=2;
            }else{
                col = m - xx;
            }
            //~ printf("%lld\n", row);

            //~ for (ll i = 1; ; i++) {
            //~ if ( x >= xx && x <= yy) {
            //~ row = i;
            //~ break;
            //~ } else {
            //~ xx = yy + 1;
            //~ yy = xx + mm;
            //~ }
            //~ }
            //~ printf("%lld %lld:::%lld\n", xx, yy, x);
            //~ printf("%lld\n", row);
            //~ if (row % 2 == 0) {
                //~ col = 2;
                //~ for (ll i = yy; i >= xx; i--) {
                    //~ if (x == i) {
                        //~ break;
                    //~ } else {
                        //~ col++;
                    //~ }
                //~ }

            //~ } else {
                //~ col = 2;
                //~ for (ll i = xx; i <= yy; i++) {
                    //~ if (x == i) {
                        //~ break;
                    //~ } else {
                        //~ col++;
                    //~ }
                //~ }
            //~ }
            //~ printf("%lld\n", col);
            printf("%lld %lld\n", row,  col);
        }
    }
    return 0;
}
