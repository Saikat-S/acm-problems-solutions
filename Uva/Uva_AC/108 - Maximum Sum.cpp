/***************************************************
 * Problem name : 108 - Maximum Sum.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 26.05.2017
 * Problem Type : kadane Algo
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
#include<climits>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define debug printf("#########\n")
#define nl printf("\n")
#define MAX 500
template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
using namespace std;
typedef long long ll;
int ar[MAX][MAX], N;
void kadane(int input[], int n, int &max) {
    int cur;
    max = 0;
    cur = 0;
    for (int i = 0; i < n; i++) {
        cur = cur + input[i];
        if (cur > max) {
            max = cur;
        }
        if (cur < 0) {
            cur = 0;
        }
    }
}
int find_max_sum() {
    int tmp[100];
    int cur, max_sum;
    int i, j, k;
    max_sum = cur = INT_MIN;

    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++)
            tmp[k] = 0;

        for (j = i; j < N; j++) {
            for (k = 0; k < N; k++)
                tmp[k] += ar[j][k];
            kadane(tmp, N, cur);

            if (cur > max_sum) {
                max_sum = cur;
            }
        }
    }
    return  max_sum;
}
int main () {
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0 ; j < N; j++) {
                scanf("%d", &ar[i][j]);
            }
        }
        int sum = find_max_sum();
        printf("%d\n", sum);
    }
    return 0;
}

