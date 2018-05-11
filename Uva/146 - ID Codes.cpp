/***************************************************
 * Problem name : 146 - ID Codes.cpp                     
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 10.05.2017                         
 * Problem Type : Stirng(AdHoc)                               
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
    string str;
    while(cin >> str){
		if(str == "#") break;
		if(next_permutation(str.begin(),str.end())){
			cout << str << endl;
		}
		else{
			cout << "No Successor" << endl;
		}
	}
    return 0;
}

