/***************************************************
 * Problem Name : Is It a Perfect Square?.cpp
 * Problem Link : https://toph.co/p/is-it-perfect-square
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-04-14
 * Problem Type : Number Theory (easy)
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
#define MAX 105
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
vector<int>prime;
char ar[MAX];
void Seive (int n) {
    ar[0] = ar[1] = 1;

    for (int i = 4; i <= n; i += 2) ar[i] = 1;

    prime.push_back (2);
    int sq = sqrt (n);

    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) ar[j] = 1;
        }
    }

    for (int i = 3; i <= n; i++) {
        if (ar[i] == 0) prime.push_back (i);
    }
}
int main () {
    __FastIO;
    Seive (100);
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int>vec (100, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            for (int j = 0; j < (int) prime.size() && prime[j] <= x; j++) {
                int cnt = 0;

                while (x % prime[j] == 0) {
                    cnt++;
                    x /= prime[j];
                }
                vec[prime[j]] += cnt;
            }
        }

        bool flag = false;

        for (int i = 2; i < 100; i++) {
            if (vec[i] != 0) {
                if (vec[i] % 2 != 0) {
                    flag = true;
                }
            }
        }

        if (flag) {
            cout << "NO\n";

        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
