/***************************************************
 * Problem Name : C. Nice Garland.cpp
 * Problem Link : https://codeforces.com/contest/1108/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-23
 * Problem Type : Div 3 - C
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
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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

void solve (int n, string str) {
    string Pat[6];

    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            while ( (int) Pat[i].size() < n) {
                Pat[i] += "BGR";
            }

        } else if (i == 1) {
            while ( (int) Pat[i].size() < n) {
                Pat[i] += "BRG";
            }

        } else if (i == 2) {
            while ( (int) Pat[i].size() < n) {
                Pat[i] += "GBR";
            }

        } else if (i == 3) {
            while ( (int) Pat[i].size() < n) {
                Pat[i] += "GRB";
            }

        } else if (i == 4) {
            while ( (int) Pat[i].size() < n) {
                Pat[i] += "RBG";
            }

        } else if (i == 5) {
            while ( (int) Pat[i].size() < n) {
                Pat[i] += "RGB";
            }
        }
    }

    int ans = INF;
    string s = "";

    for (int i = 0; i < 6; i++) {
        int cnt = 0;
        string st = "";

        for (int j = 0; j < n; j++) {
            if (str[j] != Pat[i][j]) {
                cnt++;
            }

            st += Pat[i][j];
        }

        if (ans > cnt) {
            ans = cnt;
            s.clear();
            s = st;
        }
    }

    cout << ans << "\n" << s << "\n";
}

int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    string str;
    cin >> str;
    solve (n, str);
    return 0;
}
