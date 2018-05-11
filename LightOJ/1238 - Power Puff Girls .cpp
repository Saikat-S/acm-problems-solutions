/* Problem name : 1238 - Power Puff Girls
 * OJ           : LightOJ
 * Result       : Accepted
 * Date         : 24-03-17
 * Problem Type : Graph(BFS 2D)
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define P pair<int,int>
#define MAX 100
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
char str[MAX][MAX];
bool visit[MAX][MAX];
int cost[MAX][MAX];
int row,col;
int BFS_2D(int x1,int y1,int dx,int dy) {
    //~ for(int i = 0; i<MAX; i++) {
    //~ for(int j = 0; j<MAX; j++) {
    //~ cost[i][j] = 0;
    //~ visit[i][j] = false;
    //~ }
    //~ }
    memset(visit, 0, sizeof(visit));
    memset(cost, 0, sizeof(cost));
    queue<P>Q;
    visit[x1][y1] = true;
    Q.push(P(x1,y1));
    while(!Q.empty()) {
        P top = Q.front();
        Q.pop();
        for(int i = 0; i<4; i++) {
            int xx = top.first + fx[i];
            int yy = top.second + fy[i];
            if(xx>=0 && yy>=0 && xx<row && yy<col && !visit[xx][yy] && str[xx][yy]!='#' && str[xx][yy]!='m') {
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
    int x1,x2,y1,y2,tc,dx,dy,x3,y3;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++) {
        scanf("%d %d", &row, &col);
        for(int i = 0; i<row; i++) {
            scanf("%s", str[i]);

        }
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(str[i][j] == 'a') {
                    x1 = i;
                    y1 = j;
                }
                else if(str[i][j] == 'b') {
                    x2 = i;
                    y2 = j;
                }
                else if(str[i][j] == 'c') {
                    x3 = i;
                    y3 = j;
                }
                else if(str[i][j] == 'h') {
                    dx = i;
                    dy = j;
                }
            }
        }
        int aa = BFS_2D(x1,y1,dx,dy);
        //~ for(int i = 0; i<MAX; i++) {
        //~ for(int j = 0; j<MAX; j++) {
        //~ cost[i][j] = 0;
        //~ visit[i][j] = false;
        //~ }
        //~ }
        int bb = BFS_2D(x2,y2,dx,dy);
        //~ for(int i = 0; i<MAX; i++) {
        //~ for(int j = 0; j<MAX; j++) {
        //~ cost[i][j] = 0;
        //~ visit[i][j] = false;
        //~ }
        //~ }
        int cc = BFS_2D(x3,y3,dx,dy);
        int dd = max(aa,bb);
        printf("Case %d: %d\n",t,max(cc,dd));
        //~ for(int i = 0; i<MAX; i++) {
        //~ for(int j = 0; j<MAX; j++) {
        //~ cost[i][j] = 0;
        //~ visit[i][j] = false;
        //~ }
        //~ }
    }
    return 0;
}
