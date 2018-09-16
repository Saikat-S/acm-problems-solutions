/***************************************************
 * Problem Name : E. Pencils and Boxes.cpp
 * Problem Link : http://codeforces.com/contest/985/problem/E
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-05-22
 * Problem Type : Div 2 - E  / Binary Search
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
#define MAX 500005
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
int binarySearch(ll ar[], int n, int value){
	int high = n -1, low = 0, ans = -1;
	while(high>=low){
		int mid = (high+low)/2;
		if(ar[mid] == value){
			ans = mid;
			low = mid + 1;
		}else if(ar[mid] > value){
			high = mid-1;
		}
		else low = mid + 1;
	}
	if(ans == -1 ) ans = low-1;
	
	return ans;
}
int main () {
    //~ __FastIO;
    int n, k;
    ll d;
    ll ar[MAX];
    cin >> n >> k >> d;
    for(int i = 0; i<n; i++){
		cin >> ar[i]; 
	}
	sort(ar, ar+ n);
	//~ for(int i = 0; i<n; i++){
		//~ cout << ar[i];sp;
	//~ }
	//~ nl;
	int flag = 1;
	for(int i = 0; i<n;){
		ll value = ar[i] + d;
		int x = binarySearch(ar, n, value);
		//~ cout << x ;nl;
		if(x == n-1) break;
		if(x - i +1 >= k){
			int X = n - x - 1;
			if( X < k){
				int xx = n - k - 1;
				if(xx - i >= k){
					i = xx+1;
				}
				else{
					flag = 0;
					break;
				}
			}
			else{
				i = x+1;
			}
		}
		else{
			flag = 0;
			break;
		}
		//~ cout << "i : " << i;nl;
		//~ break;
		//~ ll x = ar[i];
		//~ ll xx  = ar[i+k-1];
		//~ ll X = (xx - x);
		//~ if(X> d){
			//~ flag = 0;
			//~ break;
		//~ }
		//~ i +=k;
	}
	if(flag){
		cout << "YES\n";
	}
	else cout << "NO\n";
    return 0;
}
