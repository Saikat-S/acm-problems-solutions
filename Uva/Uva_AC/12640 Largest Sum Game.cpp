/***************************************************
 * Problem name : 12640 Largest Sum Game.cpp
 * Problem Link : https://uva.onlinejudge.org/external/126/12640.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-27
 * Problem Type : Maximum Sum(kadane)
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
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int kadane(vector<int>ar, int n) {
    int mx, sum;
    mx = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + ar[i];
        if (sum > mx) {
            mx = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return mx;
}
int main () {
    int x;
    char ch;
    vector<int>ar;
    while (scanf("%d%c", &x, &ch) == 2) {
        int flag = 0;
        if(x>0) flag = 1;
        ar.push_back(x);
        if (ch != '\n') {
            while (scanf("%d%c", &x, &ch) == 2) {
                ar.push_back(x);
                if(x>0) flag = 1;
                if(ch == '\n') break;
            }
        }
        if(!flag) printf("0\n");
        else printf("%d\n", kadane(ar, ar.size()));
        ar.clear();
    }
    return 0;
}

