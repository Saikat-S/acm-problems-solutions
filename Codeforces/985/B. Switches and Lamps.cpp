/***************************************************
 * Problem Name : B. Switches and Lamps.cpp
 * Problem Link : http://codeforces.com/contest/985/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-05-21
 * Problem Type : B
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
#define pb push_back
#define MAX 2005
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
int arr[MAX];
int main () {
	__FastIO;
    int n, m;
    string ar[MAX];
    cin >> n >>m;
    for(int i = 0; i<n; i++) {
        cin >> ar[i];
    }
    for(int j = 0; j<m; j++) {
        for(int i = 0; i<n; i++){
			if(ar[i][j] == '1'){
				arr[j]++;
			}
		}
    }
    int fg = 0;
    for(int i = 0; i<n; i++){
		int f = 0;
		for(int j = 0; j<m; j++){
			if(arr[j] == 1 && ar[i][j] == '1'){
				f = 1;
				break;
			}
		}
		if(f == 0){
			fg = 1;
			break;
		}
	}
    if(fg) {
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}

