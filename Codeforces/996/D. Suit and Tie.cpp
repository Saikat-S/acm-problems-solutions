/***************************************************
 * Problem Name : D. Suit and Tie.cpp
 * Problem Link : http://codeforces.com/contest/996/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-24
 * Problem Type : Div 2 - D
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    int ar[2 * n + 3];
 
    for (int i = 1; i <= 2 * n; i++) {
        cin >> ar[i];
    }

    //~ vector<int>v[n + 3];
    //~ for (int i = 1; i <= 2 * n; i++) {
    //~ int x = ar[i];
    //~ v[x].pb (i);
    //~ }
    //~ int ans = 0;
    int cnt = 0;

    for (int i = 1; i <= 2*n; i+=2) {
        //~ int x = abs (v[i][0] - v[i][1]);
        //~ if (x > 1) cnt++;
        //~ ans = max (ans, x);
        int tmp;
        for(int j = i+1; j<=2*n; j++){
			if(ar[i] == ar[j]){
				tmp = j;
				break;
			}
		}
		for(int k = tmp; k>i+1; k--){
			swap(ar[k], ar[k-1]);
			cnt++;
		}
    }
    cout << cnt << "\n";
    return 0;
}

