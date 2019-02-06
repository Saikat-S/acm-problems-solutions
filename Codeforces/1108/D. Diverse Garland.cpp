/***************************************************
 * Problem Name : D. Diverse Garland.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Ac
 * Date         : 2019-01-23
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
int main () {
    //~ __FastIO;
    int n;
    string str;
    cin >> n;
    cin >> str;
    int cnt = 0;

    for (int i = 1; i < n; i++) {
        if (str[i] == str[i - 1]) {
            if (str[i] == 'R') {
                if (i + 1 < n) {
                    if (str[i + 1] == 'R') {
                        str[i] = 'B';

                    } else if (str[i + 1] == 'G') {
                        str[i] = 'B';

                    } else {
                        str[i] = 'G';
                    }

                } else {
                    str[i] = 'G';
                }

            } else if (str[i] == 'G') {
                if (i + 1 < n) {
                    if (str[i + 1] == 'G') {
                        str[i] = 'B';

                    } else if (str[i + 1] == 'R') {
                        str[i] = 'B';

                    } else {
                        str[i] = 'R';
                    }

                } else {
                    str[i] = 'R';
                }

            } else if (str[i] == 'B') {
                if (i + 1 < n) {
                    if (str[i + 1] == 'B') {
                        str[i] = 'G';

                    } else if (str[i + 1] == 'G') {
                        str[i] = 'R';

                    } else {
                        str[i] = 'G';
                    }

                } else {
                    str[i] = 'G';
                }
            }

            cnt++;
        }
    }

    cout << cnt << "\n";
    cout << str << "\n";
    return 0;
}
