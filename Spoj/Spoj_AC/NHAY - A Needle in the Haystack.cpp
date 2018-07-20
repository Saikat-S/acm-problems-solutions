/***************************************************
 * Problem name : NHAY - A Needle in the Haystack.cpp
 * Problem Link : http://www.spoj.com/problems/NHAY/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2017-10-21
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
vector<int>pos;
int f[MAX];
void failure(string pattern) {
    f[0] = 0;
    int j  = 0, i = 1, len = pattern.size();
    while (i < len ) {
        if (pattern[j] == pattern[i]) {
            f[i++] = ++j;
        } else {
            if (j) {
                j = f[j - 1];
            } else {
                f[i] = 0;
                i++;
            }
        }
    }
}
void KMP_match(string txt, string patten) {
    int i = 0, j = 0, ln_t = txt.size(), ln_p = patten.size();
    int ans = -1;
    while (j < ln_t) {
        if (txt[j] == patten[i]) {
            i++, j++;
            if (i == ln_p) {
                ans = j - ln_p;
                pos.push_back(ans);
                i =  f[i - 1];
            }
        } else {
            if (i) {
                i = f[i - 1];
            } else {
                j++;
            }
        }
    }
}
int main () {
    int n, t = 1;
    string txt, patten;
    while (scanf("%d", &n) == 1) {
        getchar();
        cin >> patten >> txt;
        failure(patten);
        KMP_match(txt, patten);
        if (pos.size() != 0 ) {
            if(t!=1) nl;
            t++;
            for (int i = 0; i < (int)pos.size(); i++) {
                printf("%d\n", pos[i]);
            }
            pos.clear();
        }
    }
    return 0;
}
