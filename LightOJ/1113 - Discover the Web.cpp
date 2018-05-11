/***************************************************
 * Problem name : 1113 - Discover the Web.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1113
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-11-23
 * Problem Type : STL
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
#define MAX 100000
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        stack<string>F, B;
        string ch, url, c;
        printf("Case %d:\n", t);
        while (1) {
            cin >> ch;
            if (ch == "VISIT") {
                cin >> url;
                B.push(url);
                c.clear();
                c = url;
                cout << c << "\n";
                while(!F.empty()) F.pop();
                //~ F = stack<string>();
            } else if (ch == "BACK") {
                if (B.empty()) {
                    cout << "Ignored\n";
                } else {
                    string s = B.top();
                    B.pop();
                    F.push(s);
                    if (B.empty()) {
                        cout << "http://www.lightoj.com/\n";
                    } else {
                        cout << B.top() << "\n";
                    }
                }
            } else if (ch == "FORWARD") {
                if (F.empty()) {
                    cout << "Ignored\n";
                } else {
                    string s = F.top();
                    F.pop();
                    B.push(s);
                    cout << s << "\n";
                }
            } else if (ch == "QUIT") {
                break;
            }
        }
    }
    return 0;
}
