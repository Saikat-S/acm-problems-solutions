/***************************************************
 * Problem name : 1062 - Crossed Leadders.cpp                       
 * OJ           : LOJ                                  
 * Result       : Accepted                           
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
double x,y,c;
double BinarySearch(){
	double ab,dc,ef,ans;
	double high = min(x,y);
	double low = 0;
	for(int i = 0; i<200; i++){
		double mid = (high+low)/2.0;
		ab = sqrt((y*y - mid*mid));
		dc = sqrt((x*x - mid*mid));
		ef = (ab*dc)/(ab+dc);
		if(ef<=c){
			ans = mid;
			high = mid;
		}
		else{
			low = mid;
		}
	}
	return ans;
}
int main () {
    int tc;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
		scanf("%lf %lf %lf", &x, &y, &c);
		printf("Case %d: %lf\n",t, BinarySearch());
	}
    return 0;
}

