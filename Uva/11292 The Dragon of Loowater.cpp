/***************************************************
 * Problem name : 11292 The Dragon of Loowater.cpp
 * Problem Link : https://uva.onlinejudge.org/external/112/11292.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 08.06.2017
 * Problem Type : AdHoc
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
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
#define MAX 20005
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main () {
    int n, m;
    int ar[MAX], am[MAX];
    while (scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
        for (int i = 0; i < m; i++) scanf("%d", &am[i]);
        if (n > m) printf("Loowater is doomed!\n");
        else {
            int flag ,sum = 0;
            sort(am, am+m);
            for (int i = 0; i < n; i++) {
                int x = ar[i];
                flag = 0;
                for (int j = 0 ; j < m; j++) {
                    if(x<=am[j] && am[j] != -1){
                        flag = 1;
                        sum +=am[j];
                        am[j] = -1;
                        break;
					}
                }
                if(flag == 0){
					break;
				}
            }
            if(flag == 0) printf("Loowater is doomed!\n");
            else printf("%d\n", sum);
        }
    }
    return 0;
}

