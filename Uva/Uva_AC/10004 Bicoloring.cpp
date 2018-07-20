#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define MAX 205
using namespace std;
typedef long long ll;
vector<int>V[MAX];
int color[MAX];           ///white = 0, red = 1 ; blue = 2
int bicoloring(int s) {
    queue<int>Q;
    Q.push(s);
    color[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int sz = V[u].size();
        for (int i = 0; i < sz; i++) {
            int v = V[u][i];
            if (color[v] == 0) {
                if (color[u] == 1) {
                    color[v] = 2;
                } else {
                    color[v] = 1;
                }
                Q.push(v);
            }
            if (color[u] == color[v]) {
                return 0;
            }
        }
    }
    return 1;

}
int main() {
    int n, e;
    while (scanf("%d", &n) == 1 && n != 0) {
        scanf("%d", &e);
        for (int i = 1; i <= e; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            V[x].push_back(y);
            V[y].push_back(x);
        }
        int check = bicoloring(0);
        if (check) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }
        for (int i = 0; i < MAX; i++) {
            V[i].clear();
            color[i] = 0;
        }
    }
    return 0;
}
