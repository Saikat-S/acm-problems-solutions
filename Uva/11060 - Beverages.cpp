/***************************************************
 * Problem name : 11060 - Beverages.cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 00-03-17
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
#define MAX 105
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
map<string, int>mp;
int indegree[MAX], taken[MAX];
vector<string>list;
int N;
string str[MAX];
void topsort() {
    for (int i = 1; i <= N; i++) {
        int j ;
        for (j = 1; i <= N; j++) {
            if (!indegree[j] && !taken[j]) {
                taken[j] = 1;
                list.push_back(str[j]);
                int sz = adj[j].size();
                for (int k = 0; k < sz; k++) {
                    indegree[adj[j][k]]--;
                }
                indegree[j]--;
                break;
            }
        }
    }
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
        taken[i] = 0;
        indegree[i] = 0;
    }
    mp.clear();
    list.clear();
}
int main () {
    int  M, t = 1;
    while (scanf("%d", &N) == 1 ) {
        for (int i = 1; i <= N; i++) {
            cin >> str[i];
            mp[str[i]] = i;
        }
        cin >> M;
        for (int i = 1; i <= M; i++) {
            string u, v;
            cin >> u >> v;
            adj[mp[u]].push_back(mp[v]);
            indegree[mp[v]]++;
        }
        topsort();
        printf("Case #%d: Dilbert should drink beverages in this order: ", t++);
        for (int i = 0; i < N; i++) {
            if (i ==  N-1) {
                cout << list[i] << "." << endl<<endl;
            } else {
                cout << list[i] << " ";
            }
        }
        mem();
    }
    return 0;
}
