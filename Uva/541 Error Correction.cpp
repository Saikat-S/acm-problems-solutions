/***************************************************
 * Problem name : 541 Error Correction.cpp                       
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
#define MAX 102
using namespace std;
typedef long long ll;
int main () {
    int n;
    int ar[MAX][MAX];
    while(scanf("%d", &n) == 1  && n!=0){
		for(int  i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				scanf("%d", &ar[i][j]);
			}
		}
		int row,col,rcnt=0,ccnt=0;
		for(int i = 0; i<n; i++){
			int sum = 0;
			for(int j = 0; j<n; j++){
				sum+=ar[i][j];
			}
			if(sum%2==1){
				rcnt++;
				row = i+1;
			}
		}
		for(int i = 0; i<n; i++){
			int sum = 0;
			for(int j = 0; j<n; j++){
				sum+=ar[j][i];
			}
			if(sum%2==1){
				ccnt++;
				col = i+1;
			}
		}
		if(rcnt == 0 && ccnt == 0){
			printf("OK\n");
		}
		else if(rcnt == 1 && ccnt == 1){
			printf("Change bit (%d,%d)\n",row,col);
		}
		else{
			printf("Corrupt\n");
		}
	}
    return 0;
}

