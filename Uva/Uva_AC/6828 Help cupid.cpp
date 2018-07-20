/***************************************************
 * Problem name : 6828 Help cupid.cpp
 * Problem Link : https://uva.onlinejudge.org/external/128/12861.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
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
int main () {
    __FastIO;
    int n;
    while (cin >> n) {
        vector<int> ara(n);
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        sort(ara.begin(), ara.end());
        int m = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            bool flag = false;
            for (int j = i, k = i + 1;; j += 2, k += 2) {
                if (j >= n) j %= n;
                if (k >= n) k %= n;
                if (flag and j == i) break;
                int tmp1 = abs(ara[k] - ara[j]);
                int tmp2 = 24 - tmp1;
                sum += min(tmp1, tmp2);
                flag = true;
            }
            m = min(m, sum);
        }
        cout << m << endl;
    }
    return 0;
}
