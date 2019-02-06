/***************************************************
 * Problem Name : 11743 Credit Check.cpp
 * Problem Link : https://uva.onlinejudge.org/external/117/11743.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-10-19
 * Problem Type : Implementation
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
int digitSum (int n) {
    int sum = 0;

    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = 0;
        sum += (digitSum ( (a[0] - '0') * 2) );
        sum += (digitSum ( (a[2] - '0') * 2) );
        sum += (digitSum ( (b[0] - '0') * 2) );
        sum += (digitSum ( (b[2] - '0') * 2) );
        sum += (digitSum ( (c[0] - '0') * 2) );
        sum += (digitSum ( (c[2] - '0') * 2) );
        sum += (digitSum ( (d[0] - '0') * 2) );
        sum += (digitSum ( (d[2] - '0') * 2) );
        //~ cout << sum << " -\n";
        //~ single digit sum
        sum += (digitSum (a[1] - '0') );
        sum += (digitSum (a[3] - '0') );
        sum += (digitSum (b[1] - '0') );
        sum += (digitSum (b[3] - '0') );
        sum += (digitSum (c[1] - '0') );
        sum += (digitSum (c[3] - '0') );
        sum += (digitSum (d[1] - '0') );
        sum += (digitSum (d[3] - '0') );

        //~ cout << sum << " --\n";
        if (sum % 10 == 0) cout << "Valid\n";
        else cout << "Invalid\n";
    }

    return 0;
}
