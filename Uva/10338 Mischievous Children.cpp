/***************************************************
 * Problem name : 10338 Mischievous Children.cpp
 * Problem Link : https://uva.onlinejudge.org/external/103/10338.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 28.06.2017
 * Problem Type : AdHoc
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
#define SET(a) memset(a,0,sizeof(a))
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
/************************************ Code Start Here ******************************************************/
int main () {
    int tc;
    int aux, cont[26];
    ull N;
    string str;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cin >> str;
        SET(cont);
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            cont[str[i] - 'A']++;
        }

        N = 1;
        aux = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cont[i]; j++) {
                N = N * (aux + 1) / (1 + j);
                aux++;
            }
        }

        cout << "Data set " << t << ": " << N << endl;
    }
    return 0;
}

