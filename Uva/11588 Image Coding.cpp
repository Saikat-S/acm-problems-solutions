/***************************************************
 * Problem name : 11588 Image Coding.cpp
 * Problem Link : https://uva.onlinejudge.org/external/115/11588.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 13.06.2017
 * Problem Type : ADHoc
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
#define MAX 25
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/************************************ Code Start Here ******************************************************/
map<char, int>mp;
map<char, bool>chk;
vector<char>ans;
int main () {
    int tc, R, C, M, N;
    char str[MAX][MAX];
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d %d %d\n", &R, &C, &M, &N);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> str[i][j];
                if (mp[str[i][j]] == 0) mp[str[i][j]] = 1;
                else mp[str[i][j]]++;
            }
        }
        int mx = 0;
        char ch;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int x = mp[str[i][j]];
                if (mx <= x) {
                    mx = x;
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int x = mp[str[i][j]];
                if (mx == x && chk[str[i][j]] == 0) {
                    ch = str[i][j];
                    ans.push_back(ch);
                    chk[str[i][j]] = 1;
                }
            }
        }
        int sz = ans.size();
        int MX = sz * mx * M;
        int MN = ((C * R) - (sz * mx)) * N;
        cout <<"Case "<<t<<": "<< MX+MN <<"\n";
        
        ans.clear();
        mp.clear();
        chk.clear();
    }
    return 0;
}

