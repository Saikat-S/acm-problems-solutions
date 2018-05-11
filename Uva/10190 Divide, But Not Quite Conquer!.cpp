/***************************************************
 * Problem name : 10190 Divide, But Not Quite Conquer!.cpp
 * Problem Link : https://uva.onlinejudge.org/external/101/10190.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-22
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
int main () {
    ll n, m;
    vector<ll>ar;
    while (scanf("%lld %lld", &n, &m) == 2) {
        ar.clear();
        ar.push_back(n);
        int i = 1, flag = 0;
        if (m < 2 || n == 0 || n < m) {
            puts("Boring!");
            continue;
        }
        while (1) {
            if (n % m != 0 && n != 1) {
                flag = 1;
                break;
            }
            n = ar[i - 1] / m;
            ar.push_back(n);
            if (n == 1) break;
            i++;
        }
        if (flag) printf("Boring!\n");
        else {
            int sz = ar.size();
            for (int i = 0; i < sz; i++) {
                if (i != 0) printf(" ");
                printf("%lld", ar[i]);
            }
            nl;
        }
    }
    return 0;
}

