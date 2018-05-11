/***************************************************
 * Problem name : 12708 GCD The Largest.cpp
 * Problem Link : https://uva.onlinejudge.org/external/127/12708.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2018-04-29                         
 * Problem Type : Number Theory (GCD)                               
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
    int tc;
    ll n;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
        scanf("%lld", &n);
        if(n%2 == 0){
            printf("%lld\n", n/2);
        }
        else printf("%lld\n", (n-1)/2);
    }
    return 0;
}
