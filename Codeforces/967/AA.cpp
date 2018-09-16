/***************************************************
 * Problem name : AA.cpp
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
    int H[MAX], M[MAX];
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &H[i], &M[i]);
    }
    int h, m;
    int f = 0;
    int x = M[n] + s + 1;
    if (x >= 60) {
        int y = H[n] + 1;
        if ( y <= 24) {
            if (s == 60) {
                y = 1;
            } else {
                y = 0;
            }
            if (H[1] > y) {
                h = 0;
                m = 0;
                f = 1;
            } else if (H[1] == y) {
                if ( M[1] > s) {
                    h = 0;
                    m = 0;
                    f = 1;
                }
            }
        }
    } else {
        int y;
        if (s == 60) {
            y = 1;
        } else {
            y = 0;
        }
        if (H[1] > y) {
            h = 0;
            m = 0;
            f = 1;
        } else if (H[1] == y) {
            if ( M[1] > s) {
                h = 0;
                m = 0;
                f = 1;
            }
        }
    }
    if (f) printf("%d %d\n", h, m);
    else{
        
    }
    return 0;
}
