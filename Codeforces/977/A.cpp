/***************************************************
 * Problem name : A.cpp           
 * OJ           :                                   
 * Verdict      : AC                      
 * Date         : 2018-05-06                         
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
/************************************ Code Start Here ******************************************************/
int main () {
    //~ __FastIO;
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll cnt = 0, i;
    for(i = n ; ;){
        string str = NumberToString(i);
        int sz = str.size();
        if(str[sz-1] == '0'){
            i = i/10;
        }
        else i--;
        
        cnt++;
        
        if(cnt == k) break;
    }
    printf("%lld\n", i);
    return 0;
}
