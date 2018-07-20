/***************************************************
 * Problem name : 1056 - Olympics .cpp                       
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
double a,b;
double BinarySearch(){
	double mid,ab,bd,r,O,S,P;
	double high = 400.0;
	double low = 0.0;
	double ans;
	for(int i = 0; i<200; i++){
		mid = (high+low)/2.0;
	    ab = b/a*mid;
	    bd = sqrt((ab*ab)+(mid*mid));
	    r = bd/2.0;
	    O = acos(((r*r+r*r)-(ab*ab))/(2.0*r*r));
	    S = r*O;
	    P = ((S*2.0) + (mid*2.0));
	    if(P<=400.0){
			ans = mid;
			low = mid;
		}
		else{
			high = mid;
		}
	}
	return ans;
}
int main () {
    ll tc;
    char ch;
    scanf("%lld", &tc);
    for(ll t = 1; t<=tc; t++){
		scanf("%lf %c %lf", &a,&ch,&b);
		double ad = BinarySearch();
		double ab = b/a*ad;
		printf("Case %lld: %lf %lf\n", t,ad,ab);
	}
    return 0;
}

