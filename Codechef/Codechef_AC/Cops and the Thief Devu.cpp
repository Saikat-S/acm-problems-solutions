/***************************************************
 * Problem Name : Cops and the Thief Devu.cpp
 * Problem Link : https://www.codechef.com/problems/COPS
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-12-11
 * Problem Type : AdHoc
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
    int tc, M, x, y;
    cin >> tc;

    while (tc--) {
        cin >> M >> x >> y;
        int pulic = x * y;
        vector<int>vec, ar;

        for (int i = 0; i < M; i++) {
            int x;
            cin >> x;
            ar.pb (x);
        }

        sort (all (ar) );

        for (int i = 0; i < M; i++) {
            vec.pb (ar[i] - pulic);
            vec.pb (ar[i] + pulic);
        }

        int cnt = 0;

        if (vec[0] > 1) cnt += (vec[0] - 1);

        for (int i = 1; i < (int) vec.size(); i += 2) {
            if (vec[i] < vec[i + 1] && ( i != ( (int) vec.size() - 1) ) )  {
                cnt += ( (vec[i + 1] - vec[i]) - 1);

            } else if (i == ( (int) vec.size() - 1) ) {
                if (vec[i] < 100) {
                    cnt += (100 - vec[i]);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
