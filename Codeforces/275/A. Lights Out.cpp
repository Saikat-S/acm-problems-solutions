/***************************************************
 * Problem Name : A. Lights Out.cpp
 * Problem Link : http://codeforces.com/contest/275/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-05-24
 * Problem Type : Div 2 - A
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 5
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
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int arr[MAX][MAX];

bool isValid(int x, int y) {
    if(x >= 0 && x<3 && y >= 0 && y<3) return true;
    return false;
}
void fun(int x, int y) {
    if(arr[x][y] == 1) arr[x][y] = 0;
    else arr[x][y] = 1;
    for(int i = 0; i<4; i++) {
        int xx = fx[i] + x;
        int yy = fy[i] + y;
        if(isValid(xx, yy)) {
            if(arr[xx][yy] == 1) {
                arr[xx][yy] = 0;
            }
            else arr[xx][yy] = 1;
        }
    }
}
void Set() {
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            arr[i][j] = 1;
        }
    }
}
void print() {
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout << arr[i][j];
        }
        nl;
    }
}
int main () {
    __FastIO;
    int ar[MAX][MAX];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cin >> ar[i][j];
        }
    }
    Set();
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            if(ar[i][j]%2 == 1) {
                fun(i, j);
            }
        }
    }
    print();
    return 0;
}
