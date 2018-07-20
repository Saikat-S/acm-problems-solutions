/***************************************************
 * Problem name : 1076 - Get the Containers .cpp                       
 * OJ           : LOJ                                 
 * Result       : Accepted                           
 * Date         : 29-03-17                          
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
#define MAX 1005
using namespace std;
typedef long long ll;
ll ar[MAX],sm,n,m,mx;
ll BinarySearch(){
	ll high = sm;
	ll low = mx;
	ll ans;
	while(high>=low){
		ll mid = (high+low)/2;
		int sum = 0;
		ll chk = 1;
		for(int i = 0; i<n; i++){
			sum+=ar[i];
			if(sum>mid){
				chk++;
				sum = ar[i];
			}
		}
		if(chk<=m){
			high = mid -1;
			ans = mid;
		}
		else{
			low = mid+1;
		}
	}
	return ans;
}
int main () {
    ll tc;
    scanf("%lld", &tc);
    for(ll t = 1; t<=tc; t++){
		scanf("%lld %lld", &n, &m);
		sm = 0;
		mx = 0;
		for(int i = 0; i<n; i++){
			scanf("%lld", &ar[i]);
			if(mx<=ar[i]){
				mx = ar[i];
			}
			sm+=ar[i];
		}
		printf("Case %lld: %lld\n",t,BinarySearch());
	}
    return 0;
}

