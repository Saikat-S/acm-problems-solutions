/***************************************************
 * Problem name : 352 - The Seasonal War.cpp
 * Problem Link : https://uva.onlinejudge.org/external/3/352.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-11-08                         
 * Problem Type : Graph                               
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU                     
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 100
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int fx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int color[MAX][MAX];
int n;
string str[MAX];
void dfs(int sx, int sy) {
    color[sx][sy] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = sx + fx[i];
        int yy = sy + fy[i];
        if (xx >= 0 && yy >= 0 && xx < n && yy < n && str[xx][yy] == '1' && color[xx][yy] == 0) {
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
    int t = 1;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        mem();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (color[i][j] == 0 && str[i][j] == '1') {
                    count++;
                    dfs(i, j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", t++, count);
    }
    return 0;
}


