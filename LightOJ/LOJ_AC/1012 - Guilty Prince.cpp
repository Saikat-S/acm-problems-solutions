/* Problem name : 1012 - Guilty Prince
 * OJ           : LightOJ
 * Result       : Accepted
 * Date         : 24-03-17
 * Problem Type : Graph(BFS 2D)
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define P pair<int,int>
#define MAX 50
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
char str[MAX][MAX];
bool visit[MAX][MAX];
int row,col;
int BFS_2D(int x1,int y1) {
    //~ memset(visit, false, sizeof(visit));
    //~ for(int i = 0; i<MAX; i++) {
    //~ for(int j = 0; j<MAX; j++) {
    //~ visit[i][j] = false;
    //~ }
    //~ }
    int count = 1;
    queue<P>Q;
    visit[x1][y1] = true;
    Q.push(P(x1,y1));
    while(!Q.empty()) {
        P top = Q.front();
        Q.pop();
        for(int i = 0; i<4; i++) {
            int xx = top.first + fx[i];
            int yy = top.second + fy[i];
            if(xx>=0 && yy>=0 && xx<row && yy<col && !visit[xx][yy] && str[xx][yy]!='#') {
                count++;
                visit[xx][yy] = true;
                Q.push(P(xx,yy));
            }
        }
    }
    return count;
}
int main()
{
    int x,y,tc;
    scanf("%d", &tc);
    for(int t = 1; t<=tc; t++) {
        scanf("%d %d", &col, &row);
        for(int i = 0; i<row; i++) {
            scanf("%s", str[i]);
        }
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(str[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        int cnt = BFS_2D(x,y);
        printf("Case %d: %d\n",t,cnt);
        memset(visit, false, sizeof(visit));
        //~ for(int i = 0; i<MAX; i++) {
        //~ for(int j = 0; j<MAX; j++) {
        //~ visit[i][j] = false;
        //~ }
        //~ }
    }
    return 0;
}

