/***************************************************
 * Problem name : 1586 - Molar mass.cpp
 * OJ           : Uva 
 * Result       : AC
 * Date         : 05-04-17
 * Problem Type : AD-Hoc
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
#define MAX 100
using namespace std;
typedef long long ll;
double value(char ch) {
    if (ch == 'O') return 16.000;
    else if (ch == 'N') return 14.010;
    else if (ch == 'C') return 12.010;
    else if (ch == 'H') return 1.008;

}
int main () {
    int tc, sum;
    //~ double O = 16.000, N = 14.010, C = 12.010, H = 1.008,M;
    double M;
    char str[MAX];
    scanf("%d", &tc);
    int ar[MAX], cnt;
    for (int t = 1; t <= tc; t++) {
		cnt  = 0;
        scanf("%s", str);
        sum = 0, M = 0.0;
        int len = strlen(str);
        for (int i = 0; i < len ; i++) {
            if (isalpha(str[i])) {
                ar[cnt++] = sum;
                sum = 0;
            } else {
                sum = sum * 10 + str[i] - '0';
                if(i == len-1){
					ar[cnt++] = sum;
				}
            }
        }
        for (int i = 0, j = 1; i < len; i++) {
            if (isalpha(str[i])) {
                if (ar[j] == 0) {
                    M = M + value(str[i]) * 1.0;
                    j++;
                } else {
                    M = M + value(str[i]) * ar[j++];
                }
            }
        }
        //~ for(int i = 1; i<cnt; i++){
			//~ printf("%d ", ar[i]);
		//~ }
        printf("%.3lf\n", M);
        for(int i = 0; i<MAX;i++){
			ar[i] = 0;
		}
    }
    return 0;
}

