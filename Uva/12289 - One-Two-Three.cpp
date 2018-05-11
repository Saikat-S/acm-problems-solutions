/***************************************************
 * Problem name : 12289 - One-Two-Three.cpp                     
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 10.05.2017                         
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
#define MAX 100000
using namespace std;
typedef long long ll;
int main () {
   string s;
   int tc;
   scanf("%d", &tc);
   for(int i = 1; i<=tc; i++){
	   cin >> s;
	   if(s.size() == 5){
		printf("3\n");   
	   }
	   else{
		    int t = 0;
			if(s[0] == 'o') t++;
			if(s[1] == 'n') t++;
			if(s[2] == 'e') t++;
			if(t>=2){
				printf("1\n");
			}
			else{
				printf("2\n");
			}
	   }
   }
    return 0;
}

