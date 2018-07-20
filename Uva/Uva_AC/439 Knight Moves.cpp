/***************************************************
 * Problem name : 439 Knight Moves.cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 17-04-17
 * Problem Type : Graph
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
#define MAX 65
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 2, -2, -2, -1, 1, 2};
int fy[] = {-2, -2, -1, -1, 1, 2, 2, 1};
int visit[MAX][MAX];
int cost[MAX][MAX];
int BFS_2D(int sx, int sy,int dx,int dy) {
    cost[sx][sy] = 0;
    visit[sx][sy] = 1;
    queue<pii>Q;
    Q.push(pii(sx, sy));
    while (!Q.empty()) {
        pii top = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = top.first + fx[i];
            int yy = top.second + fy[i];
            if (xx > 0 && yy > 0 && xx <= 8 && yy <= 8 && !visit[xx][yy]) {
                cost[xx][yy] = cost[top.first][top.second] + 1;
                visit[xx][yy] = 1;
                Q.push(pii(xx, yy));
            }
        }
    }
    return cost[dx][dy];
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            visit[i][j] = 0;
            cost[i][j] = 0;
        }
    }
}
int num(char ch) {
    if (ch == 'a') return 1;
    else if (ch == 'b') return 2;
    else if (ch == 'c') return 3;
    else if (ch == 'd') return 4;
    else if (ch == 'e') return 5;
    else if (ch == 'f') return 6;
    else if (ch == 'g') return 7;
    else if (ch == 'h') return 8;
}
int main () {
    string a, b;
    while (cin >> a >> b) {
        int sx = num(a[0]);
        int sy = a[1] - '0';
        //~ BFS_2D(sx,sy);
        int dx = num(b[0]);
        int dy = b[1] - '0';
        printf("To get from %s to %s takes %d knight moves.\n", a.c_str(), b.c_str(), BFS_2D(sx,sy,dx,dy));
        mem();
    }
    return 0;
}

