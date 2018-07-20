/***************************************************
 * Problem name : 1088 - Points in segment.cpp                       
 * OJ           : LOJ                                 
 * Result       : AC                           
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
#define MAX 100005
using namespace std;
typedef long long ll;
ll ar[MAX],n,flag;
int BinarySearch(ll value) {
    ll high = n - 1;
    ll low = 0;
    ll ans = -1;
    while (high >= low) {
        ll mid = (high + low) / 2;
        if (ar[mid] == value) {
            ans = mid;
            high = mid - 1;
        } else if (ar[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == -1) {
        ans = high;
        flag = 1;
    }
    return ans+1;
}
int main () {
    ll tc,q;
    scanf("%lld", &tc);
    for(ll t = 1; t<=tc; t++){
		scanf("%lld %lld", &n, &q);
		for(ll i = 0; i<n; i++){
			scanf("%lld", &ar[i]);
		}
		printf("Case %lld:\n",t);
		for(ll i = 1; i<=q; i++){
			ll a,b;
			scanf("%lld %lld", &a, &b);
			ll AA = BinarySearch(b);
			flag = 0;
			ll A = BinarySearch(a);
			if(flag == 0){
				A = A-1;
			}
			ll ans = AA - A;
			printf("%lld\n", ans);
		}
	}
    return 0;
}

