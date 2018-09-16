/***************************************************
 * Problem name : A.cpp           
 * OJ           :                                   
 * Verdict      : AC                    
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
    int n;
    string str;
    scanf("%d", &n);
    cin >> str;
    int sunno = 0;
    for(int i = 0; i<n; i++){
        if(str[i] == '0') sunno++;
    }
    if(sunno == n) printf("0\n");
    else{
        printf("1");
        for(int i = 1; i<=sunno; i++){
            printf("0");
        }
        nl;
    }
    return 0;
}
