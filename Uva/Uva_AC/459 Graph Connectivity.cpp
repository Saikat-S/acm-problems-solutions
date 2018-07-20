/***************************************************
 * Problem name : 459 Graph Connectivity.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/459.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 02.06.2017
 * Problem Type : Union Find
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
#define MAX 100000
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
////////////////////////////// Code Start Here ////////////////////////////////////////////
//~ vector<string>par;
map<char, char>par;
void makeSet(char u) {
    par[u] = u;
}
void initUnion(char N) {
    for (char i = 'A'; i <= N; i++) {
        makeSet(i);
    }
}
char findRepresentative(char r) {
    if (par[r] == r) {
        return r;
    } else {
        par[r] = findRepresentative(par[r]);
    }

    return par[r];
}
void setUnion(char a, char b) {
    char u = findRepresentative(a);
    char v = findRepresentative(b);

    if (u != v) {
        par[u] = v;
    }
}
int main () {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        char ch;
        cin >> ch;
        initUnion(ch);
        string Edge;
        int flag = 1;
        getchar();
        while (flag) {
            getline(cin, Edge);
            int sz = Edge.size();
            if (sz == 0) {
                flag = 0;
                break;
            }
            char a = Edge[0];
            char b = Edge[1];
            //~ cout << a << " "<< b <<endl;
            setUnion(a, b);

        }
        map<char, int>mp;
        int cnt = 0;
        for (char i = 'A'; i <= ch; i++) {
            char r = findRepresentative(i);
            if (mp[r] == 0) {
                mp[r] = 1;
                cnt++;
            }
        }
        printf("%d\n", cnt);
        if (t != tc) printf("\n");
        mp.clear();
        par.clear();
    }
    return 0;
}

