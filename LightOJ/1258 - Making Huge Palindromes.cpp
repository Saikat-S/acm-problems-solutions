/***************************************************
 * Problem name : 1258 - Making Huge Palindromes.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1258                       
 * OJ           : LOJ                                  
 * Verdict      : AC                      
 * Date         : 2017-11-09                         
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
#define SET(a,v) memset(a,v,sizeof(a))
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
ll tmp[MAX];
void failure(string pattern) {
    tmp[0] = 0;
    ll j  = 0, i = 1, len = pattern.size();
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
ll KMP(string txt, string patten) {
    ll i = 0, j = 0, ln_t = txt.size(), ln_p = patten.size();
    ll cnt = 0;
    while (j < ln_t) {
        if (txt[j] == patten[i]) {
            i++, j++;
            cnt = i;
            if (i == ln_p) {
                i =  tmp[i - 1];
            }
        } else {
            //~ cnt++;
            if (i) {
                i = tmp[i - 1];
            } else {
                j++;
            }
        }
    }
    return cnt;
}
//~ ll fun(string txt, string pat) {
//~ ll cnt = 0, i = 0, j = 0;
//~ ll sz = txt.size();
//~ while (sz>i) {
//~ if(txt[i] == pat[j]){
//~ i++;
//~ j++;
//~ }
//~ else{
//~ cnt++;
//~ i++;
//~ }
//~ }
//~ ll x = sz - j;
//~ return cnt;
//~ }
int main () {
    int tc;
    string str;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        cin >> str;
        string ss = str;
        reverse(ss.begin(), ss.end());
        //~ failure(str);
        //~ for(int i  = 0;i<(int)str.size(); i++){
        //~ printf("%lld ", tmp[i]);
        //~ }
        SET(tmp, 0);
        failure(ss);
        //~ nl;
        //~ for(int i  = 0;i<(int)str.size(); i++){
        //~ printf("%lld ", tmp[i]);
        //~ }
        ll cnt = KMP(str, ss);
        //~ ll cnt =  fun(str, ss);
        //~ printf("%lld\n", cnt);
        ll sz = str.size();
        ll ans = sz  - cnt;
        printf("Case %d: %lld\n", t, (sz + ans));
        //~ for (int i = 0; i < (int)ss.size(); i++) {
        //~ printf("%lld ", tmp[i]);
        //~ }

    }
    return 0;
}
