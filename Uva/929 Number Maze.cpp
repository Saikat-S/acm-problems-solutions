/***************************************************
 * Problem name : 929 Number Maze.cpp
 * Problem Link : https://uva.onlinejudge.org/external/9/929.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 12.05.2017
 * Problem Type : Graph(dijkstra)
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
#define SET_MN(a) memset(a,0,sizeof(a))
#define SET_MX(a) memset(a,1000000,sizeof(a))
#define pii pair<int,int>
#define MAX 1000
#define nl printf("\n")
#define debug printf("#########\n")
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int ar[MAX][MAX], cost[MAX][MAX];
int M, N;
int isValid(int xx, int yy) {
    if (xx >= 0 && yy >= 0 && xx < N && yy < M) return 1;
    else return 0;
}
struct node {
    int xxx, yyy, w;
    node(int a, int b, int c) {
        xxx = a;
        yyy = b;
        w = c;
    }
    //~ bool operator < ( const node &p ) const {
    //~ return w > p.w;
    //~ }
};
bool operator <(node a , node b) {
    return a.w > b.w;
}
int dijkstra(int sx, int sy, int dx, int dy) {
    priority_queue<node>Q;
    cost[sx][sy] = ar[sx][sy];
    Q.push(node(sx, sy, cost[sx][sy]));
    while (!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int x = top.xxx;
        int y = top.yyy;
        //~ cout << x << " " << y;
        //~ nl;
        for (int i = 0; i < 4; i++) {
            //~ debug;
            int xx = x + fx[i];
            int yy = y + fy[i];
            if (isValid(xx, yy)) {
                //~ debug;
                if ((cost[x][y] + ar[xx][yy]) < cost[xx][yy]) {
                    cost[xx][yy] = cost[x][y] + ar[xx][yy];
                    //~ if(dx == xx && dy == yy){
                    //~ return cost[xx][yy];
                    //~ }
                    Q.push(node(xx, yy, cost[xx][yy]));
                }
            }
        }
    }
    return cost[dx][dy];
}
int main () {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &ar[i][j]);
            }
        }
        if (N == 1 && M == 1) {
            printf("%d\n", ar[0][0]);
        } else {
            int sx = 0, sy = 0;
            int dx = N - 1, dy = M - 1;
            SET_MX(cost);
            //~ dijkstra(sx, sy);
            printf("%d\n", dijkstra(sx, sy, dx, dy));
        }
    }
    return 0;
}

