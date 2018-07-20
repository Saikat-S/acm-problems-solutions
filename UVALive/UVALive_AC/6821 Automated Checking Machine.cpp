/***************************************************
 * Problem name : 6821 Automated Checking Machine.cpp
 * Problem Link : https://icpcarchive.ecs.baylor.edu/external/68/6821.pdf
 * OJ           : Uva Live
 * Verdict      : AC
 * Date         : 2018-05-05
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int ar[6], arr[6];
    while (scanf("%d", &ar[0]) == 1) {
        for (int i = 1; i <= 4; i++) {
            scanf("%d", &ar[i]);
        }
        int flag = 0;
        for (int i = 0; i <= 4; i++) {
            scanf("%d", &arr[i]);
            if (ar[i] == 0 && arr[i] == 0) {
                flag = 1;
            }
            if (ar[i] == 1 && arr[i] == 1) {
                flag = 1;
            }
        }
        if (flag) {
            printf("N\n");
        } else printf("Y\n");
    }
    return 0;
}
