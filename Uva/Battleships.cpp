/***************************************************
 * Problem name : Battleships.cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 20-04-17
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
#define MAX 102
using namespace std;
typedef long long ll;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
string str[MAX];
ll N;
ll color[MAX][MAX];
void DFS_2D(ll x, ll y) {
    color[x][y] = 1;
    for (ll i = 0; i < 4; i++) {
        ll xx = x + fx[i];
        ll yy = y + fy[i];
        if (xx >= 0 && yy >= 0 && xx < N && yy < N && (str[xx][yy] == 'x' || str[xx][yy] == '@')) {
            if (color[xx][yy] == 0) {
                DFS_2D(xx, yy);
            }
        }
    }
    return;
}
void mem() {
    for (ll i = 0; i < MAX ; i++) {
        for (ll j = 0; j < MAX; j++) {
            color[i][j] = 0;
        }
    }
}
int main () {
    ll tc;
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        scanf("%lld", &N);
        for (ll i = 0; i < N; i++) {
            cin >> str[i];
        }
        ll cnt = 0;
		mem();
		for(ll i = 0; i<N; i++){
			for(ll j = 0; j<N; j++){
				if(str[i][j] == 'x' && color[i][j] == 0){
					cnt++;
					DFS_2D(i,j);
					
				}
			}
		}
        printf("Case %lld: %lld\n", t, cnt);
    }

    return 0;
}

