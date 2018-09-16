/***************************************************
 * Problem name : A.cpp
 * OJ           :
 * Verdict      : Trying
 * Date         : 2018-04-29
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
#define MAX 105
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
    int n, s;
    int h[MAX], m[MAX];
    scanf("%d %d", &n, &s);
    
    for(int i = 1; i<=n; i++){
        scanf("%d %d", &h[i], &m[i]);
    }
    int f = 0;
    int H, M;
    
    int x = h[1], xx = h[n];
    int y = m[1], yy = m[n];
    
    int xx = x - 0;
    
    int tme = (xx * 60) + y;
    
    tme = 
    
    
    for(int i = 2; i<=n; i++){
        int x = h[i-1];
        int y = m[i-1];
        int xx = h[i] - x;
        
        int tme =  ((60*xx)-y ) + m[i];
        //~ printf("%d :::: %d ::::\n", i,tme);
        tme = (tme-2)/2;
        printf("%d :::: %d ::::\n", i,tme);
        if(tme > s){
            debug;
            int X = s + y + 1;
            if(X >= 60){
                H = x+1;
                M = X-60;
                f = 1;
                //~ debug;
                break;
            }else{
                H = x;
                M = X;
            }
        }
    }
    
    if(f){
        printf("%d %d\n", H, M);
    }
    else{
        int x = m[n]+s+1;
        if(x >= 60){
            H = h[n]+1;
            M = x-60;
            if(H>24){
                H = 0;
            }
        }
        printf("%d %d\n", H, M);
    }
    return 0;
}
