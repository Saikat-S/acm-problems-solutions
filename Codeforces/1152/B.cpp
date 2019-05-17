/***************************************************
 * Problem Name : B.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-24
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
bool isPow (int n) {
    return (ceil (log2 (n) ) == floor (log2 (n) ) );
}
int countBits (int number) {
    return (int) log2 (number) + 1;
}
bool checkBit (int N, int pos) {
    return (bool) (N & (1 << pos) );
}

int main () {
    __FastIO;
    int x;
    cin >> x;

    if (isPow (x + 1) == true) {
        cout << 0 << "\n";
        exit (0);
    }

    int mask = x;
    vector<int>ans;
    int cnt = 0;

    while (true) {
        int bit = countBits (mask);

        if (isPow (mask + 1) == true) {
            break;
        }

        int pos;

        for (int i = bit - 1; i >= 0; i--) {
            if (checkBit (mask, i) == false) {
                ans.pb (i + 1);
                pos = i + 1;
                mask = mask ^ ( (1 << (pos) ) - 1);
                cnt++;
                break;
            }
        }

        if (isPow (mask + 1) == true) {
            break;
        }

        mask++;
        cnt++;
    }

    cout << cnt << "\n";

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }

    nl;
    return 0;
}
