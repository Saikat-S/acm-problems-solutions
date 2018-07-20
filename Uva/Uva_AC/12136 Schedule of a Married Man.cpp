/***************************************************
 * Problem name : 12136 Schedule of a Married Man.cpp
 * Problem Link : https://uva.onlinejudge.org/external/121/12136.pdf
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
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        string ws, we, ms, me;
        cin >> ws >> we;
        cin >> ms >> me;
        //~ int Wsh,Wsm Weh,Wem,  Msh, Msm, Meh, Mem;
        int flag = 0;
        int Wsh = (ws[0]-'0')*10+(ws[1]-'0')*1,  Wsm = (ws[3]-'0')*10+(ws[4]-'0')*1;
        int Weh = (we[0]-'0')*10+(we[1]-'0')*1, Wem = (we[3]-'0')*10+(we[4]-'0')*1;
        
        int Msh = (ms[0]- '0')*10+(ms[1]-'0')*1, Msm = (ms[3]- '0')*10+(ms[4]- '0')*1;
        int Meh = (me[0]- '0')*10+(me[1]- '0')*1, Mem = (me[3]- '0')*10+(me[4]- '0')*1;
        
        double Ws = Wsh + (Wsm/100.0);
        double We = Weh + (Wem/100.0);
        double Ms = Msh + (Msm/100.0);
        double Me = Meh + (Mem/100.0);
        //~ printf("%lf %lf %lf %lf\n",Ws, We, Ms, Me);
        
        if(Ms>=Ws && Ms<=We){
            flag = 1;
        }
        else if(Me>=Ws && Me <= We){
            flag = 1;
        }
        else if(Ms<Ws && Me>We){
            flag  = 1;
        }
        
        if(!flag) printf("Case %d: Hits Meeting\n", t);
        else printf("Case %d: Mrs Meeting\n", t);
    }
    return 0;
}

