/***************************************************
 * Problem Name : A. Palindrome Dance.cpp
 * Problem Link : http://codeforces.com/contest/1040/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-12
 * Problem Type : Div 2 - A
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
    int n, W, B;
    cin >>  n >> W >> B;
    int ar[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int cost = 0;

    for (int i = 0, j = n - 1; i <= j; j--, i++) {
        if (i == j && ar[i] == 2) {
            cost += min (W, B);
            break;
        }

        if (ar[i] == ar[j]) {
            if (ar[i] == 2) {
                cost += (2 * min (W, B) );
            }

        } else {
            if (ar[i] == 2) {
                if (ar[j] == 0) cost += W;
                else cost += B;

            } else if (ar[j] == 2) {
                if (ar[i] == 0) cost += W;
                else cost += B;

            } else {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << cost << "\n";
    return 0;
}
