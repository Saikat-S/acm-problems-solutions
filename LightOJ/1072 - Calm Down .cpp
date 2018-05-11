/***************************************************
 * Problem name : 1072 - Calm Down.cpp                       
 * OJ           : LOJ                                  
 * Result       : AC                           
 * Date         : 27-04-17                          
 * Problem Type : BinarySearch                                  
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
#define pi 3.141592653
using namespace std;
typedef long long ll;
double R,n;
double BinarySearch(){
	double r,N,O,T;
	double high = R;
	double low = 0.0;
	double ans;
	for(int i = 0; i<200; i++){
		double mid = (high+low)/2.0;
		r = R - mid;
		O = acos(( 1 - (2*mid*mid)/(r*r)));
		T = (O*180.0)/pi;
		//~ printf("%lf ", T);
		N = 360.0/T;
		if(N>=n){
			ans = mid;
			low = mid;
			//~ high = mid;
		}
		else {
			//~ low = mid;
			high = mid;
		}
	}
	return ans;
}
int main () {
    int tc;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
		scanf("%lf %lf", &R, &n);
		printf("Case %d: %lf\n", t, BinarySearch());
	}
    return 0;
}

