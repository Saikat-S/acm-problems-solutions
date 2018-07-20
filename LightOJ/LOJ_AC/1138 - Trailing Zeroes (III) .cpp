/***************************************************
 * Problem name : 1138 - Trailing Zeroes (III) .cpp                       
 * OJ           : LOJ                                  
 * Result       : AC                           
 * Date         : 30-03-17                          
 * Problem Type : Binary Search                                  
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU                     
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define pii pair<int,int>
#define MAX 10000
using namespace std;
typedef long long ll;
ll Q;
ll pw(ll n){
	ll sum = 1;
	for(ll i = 1; i<=n; i++){
		sum *=5;
	}
	return sum;
}
ll BinarySearch() {
    ll high = 10000000000;
    ll low = 0;
    ll ans = -1;
    while(high>=low){
		ll mid = (high+low)/2;
		ll sum = 0;
		for(int j = 1; ; j++){
			ll limit = pw(j);
			if(limit>mid) break;
			sum = sum + mid/limit;
		}
		if(sum == Q){
			ans = mid;
			high = mid -1;
		}
		else if(sum<Q){
			low = mid + 1;
		}
		else{
			high = mid -1;
		}
	}
    return ans;
}
int main () {
    ll tc;
    scanf("%lld", &tc);
    for(ll t = 1; t<=tc; t++){
		scanf("%lld", &Q);
		ll ans = BinarySearch();
		if(ans == -1){
			printf("Case %lld: impossible\n",t);
		}
		else{
			printf("Case %lld: %lld\n",t,ans);
		}
		
	}
    return 0;
}

