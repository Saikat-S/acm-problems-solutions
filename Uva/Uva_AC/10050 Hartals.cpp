/***************************************************
 * Problem name : 10050 Hartals.cpp
 * Problem Link : https://uva.onlinejudge.org/external/100/10050.pdf
 * OJ           : Uva
 * Verdict      : Accepted
 * Date         : 27.05.2017
 * Problem Type : AdHoc
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define debug printf("#########\n")
#define nl printf("\n")
#define MAX 103
template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
using namespace std;
typedef long long ll;
int main () {
    int tc, N, P, h[MAX];
    map<int, int>mp;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d", &N, &P);
        for (int i = 0; i < P; i++) {
            scanf("%d", &h[i]);
            int f = 6, s = 7;
            //~ printf("%d %d\n", f,s);
            for (int j = h[i]; j <= N; j += h[i]) {
                //~ printf("%d %d\n", f,s);
                while(j > s) {
                    f += 7;
                    s += 7;
                }
                if (j != f && j != s) {
                    //~ printf("%d ", j);
                    mp[j] = 1;
                }
            }
            //~ nl;
        }
        int sz = mp.size();
        printf("%d\n", sz);
        mp.clear();
    }

    return 0;
}

