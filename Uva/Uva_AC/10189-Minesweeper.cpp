/***************************************************
 * Problem name : 10189-Minesweeper.cpp
 * Problem Link : https://uva.onlinejudge.org/external/101/10189.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-04-29
 * Problem Type : Adhoc
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
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 105
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int fx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;
string str[MAX];
bool isValid(int x, int y) {
    if ( x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}
int howMany(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if (isValid(xx, yy) && str[xx][yy] == '*')cnt++;
    }
    return cnt;
}
int main () {
    int t = 1;
    while (scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0) {
        for(int i = 0; i<n; i++){
            cin >> str[i];
        }
        if(t != 1) nl;
        printf("Field #%d:\n", t++);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(str[i][j] == '*') {
                    //~ ans[i][j] = '*';
                    cout << str[i][j];
                }
                else {
                    cout << howMany(i, j);
                }
            }
            nl;
        }
    }
    return 0;
}
