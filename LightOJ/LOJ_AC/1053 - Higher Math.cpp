/***************************************************
 * Problem Name : 1053 - Higher Math.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1053
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-29
 * Problem Type : Basic Math
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
#define PI 3.1415926535
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
int sq (int x) {
    return x * x;
}
bool isValid1 (vector<int>v) {
    sort (all (v) );

    if ( v[0] + v[1] < v[2] ) return false;
    else return true;
}
bool isValid2 (vector<int>v) {
    sort (all (v) );

    if ( sq (v[0])  + sq (v[1]) == sq (v[2]) ) return true;
    else return false;
}

int main () {
    //~ __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        vector<int>v (3);
        cin >> v[0] >> v[1] >> v[2];
        cout << "Case " << t << ": ";

        if (isValid1 (v) && isValid2 (v) ) {
            cout << "yes\n";

        } else {
            cout << "no\n";
        }
    }

    return 0;
}
