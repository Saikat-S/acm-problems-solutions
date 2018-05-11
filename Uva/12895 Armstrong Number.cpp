/***************************************************
 * Problem name : 12895 Armstrong Number.cpp
 * Problem Link : https://uva.onlinejudge.org/external/128/12895.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 14.06.2017
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
/************************************ Code Start Here ******************************************************/
ll Pow(ll num, ll n){
	ll sum = 1;
	for(int i = 1; i<=n; i++){
		sum = sum * num;
	}
	
	return sum;
}
int main () {
    ll tc,sum;
    string num;
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        cin >> num;
        int n = num.size();
        sum = 0;
        //~ cout << Pow(5,3);
        for(int i = 0; i<n; i++){
			sum = sum + Pow((num[i]-'0'), n);
			//~ cout << sum << "\n";
		}
		//~ cout << sum ;
		//~ nl;
		string ans = NumberToString(sum);
		if(num == ans) printf("Armstrong\n");
		else printf("Not Armstrong\n");
    }
    return 0;
}

