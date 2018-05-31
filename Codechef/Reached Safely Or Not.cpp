/***************************************************
 * Problem Name : J - Reached Safely Or Not.cpp
 * Problem Link : https://www.codechef.com/problems/ZUBREACH
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-05-25
 * Problem Type : beginner
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
#define MAX 100005
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
int x, y;
void fun(char ch) {
    if(ch == 'U')y++;
    else if(ch == 'D') y--;
    else if(ch == 'L') x--;
    else if(ch == 'R') x++;
}
int main () {
    int tc;
    int M, N, sx, sy, n;
    string str;
    cin >> tc;
    for(int t= 1; t<=tc; t++) {
        cin >> M >> N;
        cin >> sx >> sy;
        cin >> n;
        cin >> str;
        x = 0, y = 0;
        for(int i = 0; i<n; i++) {
            char ch = str[i];
            fun(ch);
        }
        if(x == sx && y == sy) {
            cout << "Case "<< t<< ": REACHED\n";
        }
        else if( x>=0 && x <M && y >=0 && y <N) {
            cout << "Case "<< t<< ": SOMEWHERE\n";
        } else {
            cout << "Case "<< t<< ": DANGER\n";
        }
    }
    return 0;
}
