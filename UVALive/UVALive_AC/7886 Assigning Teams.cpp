/***************************************************
 * Problem name : 7886 Assigning Teams.cpp
 * Problem Link : https://icpcarchive.ecs.baylor.edu/external/78/7886.pdf                       
 * OJ           : Uva Live                                  
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
#define MAX 5
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
    int ar[MAX];
    while(scanf("%d", &ar[0]) == 1){
        for(int i = 1; i<4; i++){
            scanf("%d", &ar[i]);
        }
        sort(ar, ar+4);
        int ans = abs((ar[0] + ar[3]) - (ar[1] + ar[2]));
        printf("%d\n", ans);
        
    }
    return 0;
}
