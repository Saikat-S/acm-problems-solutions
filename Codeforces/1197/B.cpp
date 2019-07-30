/***************************************************
 * Problem Name : B.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-22
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
#define MAX 200005
#define INF 1000000007
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
    cin >> n;
    int ar[MAX];
    int mx = 0, pos = -1;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];

        if (ar[i] > mx) {
            mx = ar[i];
            pos = i;
        }
    }

    int i = pos - 1, j = pos + 1;
    bool flag = false;

    while (1) {
        if (i < 0 && j >= n) break;

        if (i >= 0 && j < n) {
            if (ar[i] > ar[j]) {
                if (ar[i] < mx) {
                    mx = ar[i];
                    i--;

                } else {
                    flag = true;
                    break;
                }

            } else {
                if (ar[j] < mx) {
                    mx = ar[j];
                    j++;

                } else {
                    flag = true;
                    break;
                }
            }

        } else if (i >= 0) {
            if (ar[i] < mx) {
                mx = ar[i];
                i--;

            } else {
                flag = true;
                break;
            }

        } else if (j < n) {
            if (ar[j] < mx) {
                mx = ar[j];
                j++;

            } else {
                flag = true;
                break;
            }
        }
    }

    if (!flag) {
        cout << "YES\n";

    } else {
        cout << "NO\n";
    }

    return 0;
}
