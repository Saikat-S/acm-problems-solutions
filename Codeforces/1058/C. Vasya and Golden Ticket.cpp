/***************************************************
 * Problem Name : C. Vasya and Golden Ticket.cpp
 * Problem Link : https://codeforces.com/contest/1058/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-23
 * Problem Type : Div 2 - C
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
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int ar[MAX];

int fun (int n) {
    for (int i = 0; i <= 10000; i++) {
        int SS = 0;
        int cnt = 0;

        for (int j = 0; j < n; j++) {
            SS += ar[j];

            if (i == SS) {
                cnt++;
                SS = 0;
            }
        }

        if (SS == 0 && cnt > 1) {
            return 1;
        }
    }

    return 0;
}
int main () {
    __FastIO;
    int n;
    string str;
    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        int x = str[i] - '0';
        ar[i] = x;
    }

    if (fun (n) ) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
