/***************************************************
 * Problem name : 1043 - Triangle Partitioning .cpp                       
 * OJ           : LOJ                                 
 * Result       : AC                           
 * Date         : 06-04-17                          
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
double ab,ac,bc,val;
double BinarySearch(){
	double mid,ae,de,ade,s,abc,ss,bced,value;
	double high = ab;
	double low = 0;
	double ans;
	for(int i = 0; i<200; i++){
	    mid = (high+low)/2.0;
		ae = (mid * ac)/ab;
		de = (mid * bc)/ab;
		s = (mid + ae + de)/2.0;
		ade = sqrt(s*(s-mid) * (s - ae) * (s - de));
		ss = (ab + bc + ac)/2.0;
		abc = sqrt(ss*(ss-ab) * (ss - ac) * (ss - bc));
		bced = abc - ade;
		value = ade/bced;
		if(value > val){
			//ans = mid;
			high = mid;
		}
		else if(value<=val){
			ans = mid;
			low = mid;
		}
	}
	return ans;
}
int main () {
    ll tc;
    scanf("%lld", &tc);
    for(ll t = 1; t<=tc; t++){
		scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &val);
		
		printf("Case %lld: %lf\n",t,BinarySearch());
	}
    return 0;
}
