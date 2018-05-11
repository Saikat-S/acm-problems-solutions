/***************************************************
 * Problem name : 12802 Gift From the Gods.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 29.06.2017
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
#define MAX  1000005
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
bool ar[MAX];
void sieve() {
    ll sqrtMAX = sqrt(MAX);
    ar[1] = 1;
    for (ll i = 2; i <= sqrtMAX; i++) {
        if (ar[i] == 0) {
            for (ll j = i + i; j <= MAX; j += i) {
                ar[j] = 1;
            }
        }
    }
}
bool isPalindrome(string str){
	string s = str;
	reverse(s.begin(), s.end());
	if(s == str) return 1;
	else return 0;
}
int main () {
    ll n,ans;
    sieve();
    while (scanf("%lld", &n) == 1) {
        ans = n * 2;
        string str = NumberToString(n);
        bool chk = isPalindrome(str);
        printf("%lld\n", ans);
        if(chk == 1 && ar[n] == 0){
			break;
		}
    }
    return 0;
}

