/***************************************************
 * Problem Name : B. Segment Occurrences.cpp
 * Problem Link : http://codeforces.com/contest/1016/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-08-04
 * Problem Type : Educational - B
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int N, n, Q;
    cin >> N >> n >> Q;
    string str, t;
    cin >> str >> t;
    vector<int>ans;
    int sum[N + 3];
    SET (sum, 0);
    int cnt = 0;

    for (int i = 0; i < (int) str.size(); i++) {
        int c = 0;

        for (int j = i; c < n && j < N; j++, c++) {
            if (str[j] != t[c]) break;
        }

        if (c == n) {
            cnt++;
        }

        sum[i] = cnt;
    }

    for (int q = 1; q <= Q; q++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if ( (y - x) + 1 >= n) {
            int a = sum[x];
            int b = sum[y - n + 1];
            string s = str.substr (x, n);

            if (s == t) a--;

            cout << (b - a) << "\n";

        } else cout << "0\n";
    }

    return 0;
}
/*
10 3 4
codeforces
for
1 3
3 10
5 6
5 7

0
1
0
1


15 2 3
abacabadabacaba
ba
1 15
3 4
2 14


4
0
3


3 5 2
aaa
baaab
1 3
1 1

0
0
* */
