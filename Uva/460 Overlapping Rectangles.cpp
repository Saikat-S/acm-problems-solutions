/***************************************************
 * Problem name : 460 Overlapping Rectangles.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/460.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 03.06.2017
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main () {
    int tc;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
		int x2,y2,a2,b2;
		int x1,y1,a1,b1;
		int x,y,a,b;
		scanf("%d %d %d %d", &x1, &y1, &a1, &b1);
		scanf("%d %d %d %d", &x2, &y2, &a2, &b2);
		x = max(x1,x2);
		y = max(y1,y2);
		a = min(a1,a2);
		b = min(b1,b2);
		if(x>=a || y >=b) printf("No Overlap\n");
		else printf("%d %d %d %d\n",x, y, a, b);
		if(t!=tc) nl;
	}
    return 0;
}

