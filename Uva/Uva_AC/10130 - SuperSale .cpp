/***************************************************
 * Problem name : 10130 - SuperSale.cpp                       
 * OJ           : Uva                                  
 * Result       : AC                           
 * Date         : 19-04-17                          
 * Problem Type : DP                             
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
int n,p[MAX],w[MAX],ww;
int dp[MAX][32];
int knapSack(int i,int W){
	if(i == n+1) return 0;
	if(dp[i][W]!=-1) return dp[i][W];
	int pro1 = 0, pro2 = 0;
	if(W>=w[i]) pro1 = p[i] + knapSack(i+1, W-w[i]);
	else pro1 = 0;
	pro2 = knapSack(i+1,W);
	
	return dp[i][W] = max(pro1,pro2);
}
int main () {
    int tc;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			scanf("%d %d", &p[i], &w[i]);
		}
		int N,sum = 0;
		scanf("%d", &N);
		memset(dp,-1,sizeof(dp));
		for(int i = 1; i<=N; i++){
			scanf("%d",&ww);
			sum+=knapSack(1,ww);
		}
		printf("%d\n", sum);
	}
    return 0;
}
