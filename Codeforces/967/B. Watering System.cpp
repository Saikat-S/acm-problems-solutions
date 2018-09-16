/***************************************************
 * Problem name : B. Watering System.cpp           
 * OJ           :                                   
 * Verdict      : AC                    
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
    ll n, A, B;
    ll ar[MAX];
    scanf("%lld %lld %lld", &n, &A, &B);
    ll sum = 0;
    for(int i = 1; i<=n; i++){
        scanf("%lld", &ar[i]);
        sum+=ar[i];
    }
    sort(ar+2, ar+n+1);
    ll cnt = 0, s = 0;
    for(int i = n; i>=1; i--){
        int x = (A * ar[1])/(sum-s);
        if(x >= B){
            printf("%lld\n", cnt);
            break;
        }
        else {
            cnt++;
            s +=ar[i];
        }
    }

    return 0;
}
