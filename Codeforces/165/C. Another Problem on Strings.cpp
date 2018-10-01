/***************************************************
 * Problem Name : C. Another Problem on Strings.cpp
 * Problem Link : https://codeforces.com/contest/165/problem/C
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-10-01
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
int twoPointer (int k, string str) {
    int n = (int) str.size();
    int i = 0, j = 0, cnt = 0, ans = 0;

    while (1) {
        //~ debug;
        if (j == n) {
            if (str[i] == '1') cnt--;

            if (cnt == k) {
                ans++;
                //~ cout << "j==n && i " << ans << "\n";
            }

            i++;

            if (i == n) break;

        } else if (str[j] == '1' && cnt < k ) {
            cnt++;

            if (cnt == k) {
                ans++;
                //~ cout << "j && 1 " << ans << "\n";
            }

            j++;
            //~ if (j == n && cnt < k) break;

        } else if (str[j] == '1' && cnt == k ) {
            if (str[i] == '1') cnt--;

            if (cnt == k) {
                ans++;
                //~ cout << "j && i++ " << ans << "\n";
            }

            i++;

        } else if (str[j] == '0') {
            if (cnt == k) ans++;

            j++;

        } else {
            //~ if (cnt == k) {
                //~ ans++;
                //~ cout << "cnt == k " << ans << "\n";
                //~ j++;

            //~ } else if (cnt > k) {
                //~ if (str[i] == '1') cnt--;

                //~ i++;

                //~ if (i == n) break;
            //~ }
        }
    }

    //~ if (ans != 0) ans++;

    return ans;
}

int main () {
    //~ __FastIO;
    int k;
    string str;
    cin >> k >> str;
    cout << twoPointer (k, str) << "\n";
    return 0;
}
