/***************************************************
 * Problem name : 1227 - Boiled Eggs .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1227                       
 * OJ           : LOJ                                 
 * Verdict      : AC                      
 * Date         : 2017-07-17                        
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
#define MAX 31
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
    int tc,n,P,Q;
    int ar[MAX];
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
        scanf("%d %d %d", &n, &P, &Q);
        for(int i = 0; i<n; i++){
            scanf("%d", &ar[i]);
        }
        int sum = 0,cnt=0;
        for(int i = 0; i<n; i++){
            if((i + 1)<=P){
                sum+=ar[i];
                if(sum<=Q)cnt++;
                else break;
            }
        }
        printf("Case %d: %d\n", t, cnt);
    }
    return 0;
}
