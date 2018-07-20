/***************************************************
 * Problem name : 572 Oil Deposits.cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 16-04-17
 * Problem Type : Graph(2D BFS)
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
#define MAX 105
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int color[MAX][MAX];
int row, col;
string str[MAX];
void dfs(int sx, int sy) {
    color[sx][sy] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = sx + fx[i];
        int yy = sy + fy[i];
        if (xx >= 0 && yy >= 0 && xx < row && yy < col && str[xx][yy] == '1' && color[xx][yy] == 0) {
            dfs(xx, yy);
        }
    }
    color[sx][sy] = 2;
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            color[i][j] = 0;
        }
    }
}
int main () {
    while (scanf("%d %d", &row, &col) == 2 && row != 0) {
        for (int i = 0; i < row; i++) {
            cin >> str[i];
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (color[i][j] == 0 && str[i][j] == '1') {
                    count++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", count);
        mem();
    }
    return 0;
}


