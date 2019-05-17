/***************************************************
 * Problem Name : C2.cpp
 * Problem Link : https://codeforces.com/contest/1157/problem/C2
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-26
 * Problem Type : Div 3 - C2
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
#define MAX 200005
#define INF 1000000000
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
int main () {
    __FastIO;
    int n;
    int ar[MAX];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<int>ansL, ansR;
    int pre = 0;

    for (int i = 0, j = n - 1; i <= j;) {
        if (ar[i] > ar[j] && ar[j] > pre) {
            ansL.pb (1);
            pre = ar[j];
            j--;

        } else if (ar[i] < ar[j] && ar[i] > pre) {
            ansL.pb (0);
            pre = ar[i];
            i++;

        } else if (ar[i] == ar[j]) {
            for (int ii = i; ii <= j; ii++) {
                if (ar[ii] > pre) {
                    ansL.pb (0);
                    pre = ar[ii];

                } else {
                    break;
                }
            }

            break;

        } else if (ar[i] > pre) {
            ansL.pb (0);
            pre = ar[i];
            i++;

        } else if (ar[j] > pre) {
            ansL.pb (1);
            pre = ar[j];
            j--;

        } else {
            break;
        }
    }

    pre = 0;

    for (int i = 0, j = n - 1; i <= j;) {
        if (ar[i] > ar[j] && ar[j] > pre) {
            ansR.pb (1);
            pre = ar[j];
            j--;

        } else if (ar[i] < ar[j] && ar[i] > pre) {
            ansR.pb (0);
            pre = ar[i];
            i++;

        } else if (ar[i] == ar[j]) {
            for (int jj = j; jj >= i; jj--) {
                if (ar[jj] > pre) {
                    ansR.pb (1);
                    pre = ar[jj];

                } else {
                    break;
                }
            }

            break;

        } else if (ar[i] > pre) {
            ansR.pb (0);
            pre = ar[i];
            i++;

        } else if (ar[j] > pre) {
            ansR.pb (1);
            pre = ar[j];
            j--;

        } else {
            break;
        }
    }

    if ( (int) ansL.size() >= (int) ansR.size() ) {
        cout << (int) ansL.size() << "\n";

        for (int i = 0; i < (int) ansL.size(); i++) {
            if (ansL[i] == 0) {
                cout << "L";

            } else {
                cout << "R";
            }
        }

    } else {
        cout << (int) ansR.size() << "\n";

        for (int i = 0; i < (int) ansR.size(); i++) {
            if (ansR[i] == 0) {
                cout << "L";

            } else {
                cout << "R";
            }
        }
    }

    nl;
    return 0;
}
