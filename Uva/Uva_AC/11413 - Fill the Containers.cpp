/***************************************************
 * Problem name : 11413 - Fill the Containers.cpp                       
 * OJ           : Uva                                 
 * Result       : AC                           
 * Date         : 07-04-17                          
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
#define MAX 10005 
using namespace std;
typedef long long ll;
ll ar[MAX],sum,mx,n,m;
ll BinarySearch(){
	ll high = sum;
	ll low = mx;
	ll ans;
	while(high>=low){
		ll mid = (high+low)/2;
		int sm = 0,box = 1;
		for(int i = 0; i<n; i++){
			sm+=ar[i];
			if(sm>mid){
				box++;
				sm = ar[i];
			}
		}
		if(box<=m){
			ans = mid;
			high = mid -1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}
int main () {
    while(scanf("%lld %lld", &n, &m) == 2){
		sum = 0, mx = 0;
		for(ll i = 0; i<n; i++){
			scanf("%lld", &ar[i]);
			sum+=ar[i];
			mx = max(mx,ar[i]);
		}
		printf("%lld\n",BinarySearch());
	}
    return 0;
}

