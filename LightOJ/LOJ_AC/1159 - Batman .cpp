/***************************************************
 * Problem name : 1159 - Batman.cpp                       
 * OJ           : LOJ                                  
 * Result       : AC                           
 * Date         : 26-03-17                          
 * Problem Type : LCS                                  
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
#define MAX 51
using namespace std;
typedef long long ll;
string A, B,C;
int dp[MAX][MAX][MAX];
int LCS(int i, int j,int k){
	if(A[i] == '\0' || B[j] == '\0' || C[k] == '\0') return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	int ans = 0;
	if(A[i] == B[j]  && B[j] == C[k]) ans = 1+ LCS(i+1, j+1,k+1);
	else{
		int val1 = LCS(i+1,j,k);
		int val2 = LCS(i+1,j+1,k);
		int val3 = LCS(i+1,j,k+1);
		int val4 = LCS(i,j+1,k);
		int val5 = LCS(i,j,k+1);
		int val6 = LCS(i,j+1,k+1);
		int v1 = max(val1,val2);
		int v2 = max(val3,val4);
		int v3 = max(val5,val6);
		int v = max(v1,v2);
		ans = max(v,v3);
	}
	return dp[i][j][k] = ans;
}
int main () {
	std::ios_base::sync_with_stdio(false);
	int tc;
	cin>>tc;
    for(int t = 1; t<=tc; t++){
		cin>>A>>B>>C;
		//~ getline(cin,A);
		//~ getline(cin, B);
		//~ getline(cin, C);
		SET(dp);
		printf("Case %d: %d\n",t,LCS(0,0,0));
	}
    return 0;
}
