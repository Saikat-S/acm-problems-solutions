/* Problem name : 10653 - Bombs! NO they are Mines!!
 * OJ           : UVA
 * Result       : Accepted
 * Date         : 24-03-17
 * Problem Type : Graph(BFS 2D)
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define P pair<int,int>
#define MAX 1005
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
//~ vector<int>W[MAX];
int W[MAX][MAX];
bool visit[MAX][MAX];
int cost[MAX][MAX];
int R,C;
int BFS_2D(int x,int y,int dx,int dy) {
    queue<P>Q;
    visit[x][y] = true;
    cost[x][y] = 0;
    Q.push(P(x,y));
    while(!Q.empty()) {
        P top = Q.front();
        Q.pop();
        for(int i = 0; i<4; i++) {
            int xx = top.first + fx[i];
            int yy = top.second + fy[i];
            if(xx>=0 && yy>=0 && xx<R && yy<C && !visit[xx][yy] && W[xx][yy]!=1) {
                visit[xx][yy] = true;
                cost[xx][yy] = cost[top.first][top.second] + 1;
                Q.push(P(xx,yy));
            }
        }
    }
    return cost[dx][dy];
}
int main()
{
    int n,r,row;
    while(scanf("%d %d", &R, &C) == 2 && R!=0 && C!=0) {
        scanf("%d", &row);
        for(int i = 0; i<row ; i++) {
            scanf("%d %d", &r, &n);
            for(int j = 0; j<n; j++) {
                int bomb;
                scanf("%d", &bomb);
                W[r][bomb] = 1;                     // Bomb = 1;
                //~ W[r][bomb] = 1;
            }
        }
        int x,y,dx,dy;
        scanf("%d %d %d %d",&x,&y,&dx,&dy);
        //~ int c = BFS_2D(x,y,dx,dy);
        printf("%d\n",BFS_2D(x,y,dx,dy));
        //~ memset(visit, 0, sizeof(visit));
        //~ memset(cost, 0, sizeof(cost));
        //~ memset(W, 0, sizeof(W));
        for(int i = 0; i<MAX; i++) {
            for(int j = 0; j<MAX; j++) {
                visit[i][j] = false;
                cost[i][j] = 0;
                W[i][j] = 0;
            }
            //~ W[i].clear();
        }
    }
    return 0;
}
