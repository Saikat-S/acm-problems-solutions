/***************************************************
 * Problem Name : A. Many Equal Substrings.cpp
 * Problem Link : http://codeforces.com/contest/1029/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-04
 * Problem Type : Div 3 - A
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
    int n, k;
    string s, ans;
    cin >> n >> k;
    cin >> s;

    if (k == 1) {
        cout << s << "\n";
        return 0;
    }

    int cnt = 1;
    ans = s;

    for (int i = 1;;) {
        if (i == (int) ans.size() ) {
            ans += s;
            cnt++;
            i = (int) ans.size() - n + 1;

        } else if (ans[i] == s[0]) {
            int k, j;

            for (k = i, j = 0; k < (int) ans.size(); k++, j++) {
                if (j == n) break;

                if (ans[k] != s[j]) {
                    i++;
                    break;
                }
            }

            if (j == n) {
                cnt++;
            }

            if (k == (int) ans.size() ) {
                for (int l = j; l < n; l++) ans += s[l];

                cnt++;
                i = (int) ans.size() - n + 1;
            }

        } else i++;

        if (cnt == k) break;
    }

    cout << ans;
    return 0;
}
