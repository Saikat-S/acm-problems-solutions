/***************************************************
 * Problem name : 621 Secret Research.cpp                       
 * OJ           : Uva                                  
 * Result       : AC                          
 * Date         : 01-05-2017                          
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
    int tc;
    string s;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++){
		cin >> s;
		int sz = s.size();
		if((s[0]-'0' == 1 && sz ==1) || (s[0]-'0' == 4 && sz ==1) || (sz == 2 && s[0]-'0' == 7 && s[1]-'0' == 8)){
			printf("+\n");
		}
		else if(s[sz-1] == '5' && s[sz-2] == '3'){
			printf("-\n");
		}
		else if(s[0] == '9' && s[sz-1] == '4'){
			printf("*\n");
		}
		else{
			printf("?\n");
		}
	}
    return 0;
}

