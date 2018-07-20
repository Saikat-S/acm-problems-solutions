/***************************************************
 * Problem name : Camel Case.cpp
 * Problem Link :
 * OJ           :
 * Verdict      : Trying
 * Date         : 09.05.2017
 * Problem Type :
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
int isCapital(char);
int isCapital(char ch){
	if(ch >= 'A' && ch <= 'Z') return 1;
	else return 0;
}
int main () {
    string s;

    cin >> s;
    int sz = s.size();
    int cnt = 1;
    for (int i = 0; i < sz; i++) {
        if(isCapital(s[i])){
			cnt++;
		}
    }
    printf("%d\n",cnt);
    return 0;
}

