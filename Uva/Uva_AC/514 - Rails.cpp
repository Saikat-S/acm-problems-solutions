/***************************************************
 * Problem Name : 514 - Rails.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/514.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-17
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
    int n;

    while (cin >> n) {
        if (n == 0) break;

        int ar[n + 3];

        while (cin >> ar[0]) {
            if (ar[0] == 0) {
                nl; break;
            }

            for (int i = 1; i < n; i++) {
                cin >> ar[i];
            }

            stack<int>st;

            for (int i = 1, j = 0; i <= n; i++) {
                //~ debug;
                st.push (i);

                while (!st.empty() && st.top() == ar[j]) {
                    st.pop();
                    j++;
                }
            }

            if (st.empty() ) {
                cout << "Yes\n";

            } else cout << "No\n";
        }
    }

    return 0;
}
