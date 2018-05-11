/***************************************************
 * Problem name : 383 Shipping Routes.cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 00-03-17
 * Problem Type : Graph(DFS)
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
//~ int cost[MAX];
//~ bool visit[MAX];
vector<string>V[MAX];
//~ vector<string>cost;
//~ vector<string>visit;
//~ map<string, int>mp;
map<string, int>mp, visit, cost;
int BFS(string s, string d) {
    queue<string>Q;
    //~ visit[mp[s]] = true;
    //~ cost[mp[s]] = 0;
    visit[s] = 1;
    cost[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        string  u = Q.front();
        Q.pop();
        int sz = V[mp[u]].size();
        for (int i = 0; i < sz; i++) {
            string v = V[mp[u]][i];
            while (!visit[v]) {
                cost[v] = cost[u] + 1;
                visit[v] = true;
                Q.push(v);
            }
        }
    }
    return cost[d];
}
void mem() {
    //~ memset(cost,0,sizeof(cost));
    //~ memset(visit,false,sizeof(visit));
    visit.clear();
    cost.clear();
}
int main () {
    int Node, Edge, tc, Case;
    scanf("%d", &tc);
    cout << "SHIPPING ROUTES OUTPUT" << endl;
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d %d", &Node, &Edge, &Case);
        for (int i = 1; i <= Node; i++) {
            string x;
            cin >> x;
            mp[x] = i;
        }
        for (int i = 1; i <= Edge; i++) {
            string a, b;
            cin >> a >> b;
            V[mp[a]].push_back(b);
            V[mp[b]].push_back(a);
        }
        cout << "\nDATA SET  " << t << endl << endl;
        for (int i = 1; i <= Case; i++) {
            int num;
            string s, d;
            cin >> num >> s >> d;
            mem();
            //~ cout << BFS(s, d) << endl;
            int c = BFS(s, d);
            if (c != 0) {
                int C = c * 100 * num;
                cout << "$" << C << endl;
            } else {
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }
        }
        mp.clear();
        for (int i = 0; i < MAX; i++) {
            V[i].clear();
        }
    }
    cout<<"\nEND OF OUTPUT"<<endl;
    return 0;
}

