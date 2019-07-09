/***************************************************
 * Problem Name : N Factorial!.cpp
 * Problem Link : https://toph.co/p/n-factorial
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-04-14
 * Problem Type : Easy
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
#define MAX 100005
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

ll fact (ll n) {
    ll sum = 1;

    for (ll i = 1; i <= n; i++) {
        sum *= i;
    }

    return sum;
}

int main () {
    //~ __FastIO;
    int tc;
    ll n;
    cin >> tc;

    while (tc--) {
        cin >> n;

        if (n >= 20) {
            cout << "0000\n";

        } else {
            string str = NumberToString (fact (n) );

            if (int (str.size() ) > 4) {
                for (int i = (int) str.size() - 4; i < (int) str.size(); i++) {
                    cout << str[i];
                }

                nl;

            } else {
                for (int i = 1; i <= (4 - (int) str.size() ); i++) {
                    cout << "0";
                }

                cout << str << "\n";
            }
        }
    }

    return 0;
}
