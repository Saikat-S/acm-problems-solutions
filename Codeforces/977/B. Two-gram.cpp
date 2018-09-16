/***************************************************
 * Problem name : B. Two-gram.cpp
 * OJ           :
 * Verdict      : AC
 * Date         : 2018-05-06
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
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int n;
    string str;
    cin >> n;
    cin >> str;
    int mx = 0;
    string ans;
    for (int i = 0; i < n-1; i++) {
        string s = str.substr(i, 2);
        int cnt = 1;
        for (int j = i + 1; j < n-1; j++) {
            string ss  = str.substr(j, 2);
            if (ss == s) cnt++;
        }
        if (cnt > mx) {
            mx = cnt;
            ans = s;
        }
    }
    cout << ans << "\n";
    return 0;
}
