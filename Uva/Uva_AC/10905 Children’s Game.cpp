/***************************************************
 * Problem Name : 10905 Children’s Game.cpp
 * Problem Link : https://uva.onlinejudge.org/external/109/10905.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-23
 * Problem Type : AdHoc
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
#define MAX 51
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
int main () {
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    int N;
    vector<string>num;
    while (scanf("%d", &N) == 1 && N != 0) {
        getchar();
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            num.push_back(s);
        }
        string str;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((num[i] + num[j]) < (num[j] + num[i])) {
                    string s = num[j];
                    num[j] = num[i];
                    num[i] = s;
                }
            }
            str+=num[i];
        }
        cout << str << "\n";
        num.clear();
    }
    return 0;
}

