/***************************************************
 * Problem name : 11498 Division of Nlogonia.cpp                       
 * OJ           : Uva                                  
 * Result       : AC                           
 * Date         : 03-05-2017                          
 * Problem Type : AdHoc                                  
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
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define MAX 10000
using namespace std;
typedef long long ll;
int main () {
    ll n,x,y,dx,dy;
    while(scanf("%lld", &n) == 1 && n!=0){
		scanf("%lld %lld", &dx,&dy);
		for(int t = 1; t<=n; t++){
			scanf("%lld %lld", &x,&y);
			if(x == dx || y == dy){
				printf("divisa\n");
			}
			else{
				int xx = x  - dx;
				int yy = y - dy;
				if(xx<0 && yy>0){
					printf("NO\n");
				}
				else if( xx > 0 && yy >0){
					printf("NE\n");
				}
				else if(xx<0 && yy<0){
					printf("SO\n");
				}
				else if(xx>0 && yy<0){
					printf("SE\n");
				}
			}
		}
	}
    return 0;
}

