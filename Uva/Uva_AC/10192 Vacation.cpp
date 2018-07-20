/***************************************************
 * Problem name : 10192 Vacation.cpp                       
 * OJ           : Uva                                  
 * Result       : AC                           
 * Date         : 28-04-17                          
 * Problem Type : DP(LCS)                                  
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
int dp[MAX][MAX];
string A,B;
int LCS(int i, int j){
	if(A[i] == '\0' || B[j] == '\0') return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans = 0;
	if(A[i] == B[j]) ans = 1+ LCS(i+1, j+1);
	else{
		int val1 = LCS(i+1,j);
		int val2 = LCS(i,j+1);		
		ans = max(val1,val2);
	}
	return dp[i][j] = ans;
}
int main () {
	int t = 1;
    while(getline(cin,A)){
		if(A[0] == '#') break;
		getline(cin,B);
		SET(dp);
		printf("Case #%d: you can visit at most %d cities.\n",t++,LCS(0,0));
	}
    return 0;
}

