/***************************************************
 * Problem name : 1255 - Substring Frequency .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1255                       
 * OJ           : LOJ                                  
 * Verdict      : AC                     
 * Date         : 2017-10-22                         
 * Problem Type : String Matching(KMP)                               
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
#define MAX 1000005
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
int tmp[MAX];
void failure(string pattern) {
    tmp[0] = 0;
    int j  = 0, i = 1, len = pattern.size();
    while (i < len ) {
        if (pattern[j] == pattern[i]) {
            tmp[i++] = ++j;
        } else {
            if (j) {
                j = tmp[j - 1];
            } else {
                tmp[i] = 0;
                i++;
            }
        }
    }
}
int KMP(string txt, string patten) {
    int i = 0, j = 0, ln_t = txt.size(), ln_p = patten.size(),cnt = 0;
    //int ans = -1;
    while (j < ln_t) {
        if (txt[j] == patten[i]) {
            i++, j++;
            if (i == ln_p) {
                //ans = j - ln_p;
                //~ printf("Match %d index\n", ans);
                cnt++;
                i =  tmp[i - 1];
            }
        } else {
            if (i) {
                i = tmp[i - 1];
            } else {
                j++;
            }
        }
    }
    return cnt;
}
int main () {
    int tc;
    string text, patten;
    scanf("%d", &tc);
    getchar();
    for(int t = 1; t<=tc;t++){
        cin>>text>>patten;
        failure(patten);
        int ans = KMP(text, patten);
        printf("Case %d: %d\n", t, ans);
    } 
    return 0;
}

