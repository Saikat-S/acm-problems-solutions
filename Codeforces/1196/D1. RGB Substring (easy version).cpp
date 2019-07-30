/***************************************************
 * Problem Name : D1. RGB Substring (easy version).cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-24
 * Problem Type :
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MAX 2006
#define INF 1000000009
#define MOD 1000000007
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

bool check (char now, char ch) {
    if (now == 'R' && ch == 'B') return true;
    else if (now == 'G' && ch == 'R') return true;
    else if (now == 'B' && ch == 'G') return true;
    else return false;
}
bool check1 (char now, char ch) {
    if (now == 'R' && ch == 'B') return true;
    else if (now == 'G' && ch == 'R') return true;
    else if (now == 'B' && ch == 'G') return true;
    else return false;
}

int main () {
    __FastIO;
    int q, n, k;
    string str, tmp;
    string ans = "RGB";
    cin >> q;

    while (q--) {
        cin >> n >> k;
        cin >> str;
        tmp = str;
        int sum[MAX];
        SET (sum, 0);
        vector<pii>vec;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                sum[i] = 1;

            } else {
                if (check (str[i], str[i - 1]) ) {
                    sum[i] = sum[i - 1] + 1;

                } else {
                    sum[i] = 1;
                }
            }

            vec.pb ({sum[i], i});
        }

        // hello fucking ...
        int mn = INF;

        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < 3; j++) {
                int cnt = 0;

                for (int l = 0; l < k; l++) {
                    if (str[i + l] != ans[ (l + j) % 3]) {
                        cnt++;
                    }
                }

                mn = min (mn, cnt);
            }
        }

        cout << mn << "\n";
    }

    return 0;
}
