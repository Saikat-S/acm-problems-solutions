/***************************************************
 * Problem name : 612 - DNA Sorting.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 09.06.2017
 * Problem Type : AdHOc(Sorting)
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
#define MAX 103
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main () {
    int tc, n, m, sum[MAX];
    string str[MAX];
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            cin >> str[i];
        }
        for (int k = 0; k < m; k++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (str[k][i] > str[k][j]) cnt++;
                }
            }
            sum[k] = cnt;
        }
        //~ debug;
        vector<pii>ar;
        for(int i = 0; i<m; i++){
			ar.push_back(make_pair(sum[i], i));
		}
		sort(ar.begin(), ar.end());
        for(int i = 0; i<m; i++){
			cout << str[ar[i].second];
			nl;
		}
		if(t != tc) printf("\n");
		ar.clear();
    }
    return 0;
}

