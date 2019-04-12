/***************************************************
 * Problem Name : B. Nirvana.cpp
 * Problem Link : https://codeforces.com/contest/1143/problem/B
 * OJ           : Codeforces
 * Verdict      : AC	
 * Date         : 2019-03-31
 * Problem Type : Div 2 - B
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
ll digitProduct (ll num) {
    ll pro = 1;

    while (num > 0) {
        pro *= (num % 10LL);
        num /= 10LL;
    }

    return pro;
}

ll findMaxNumber (ll l, ll r) {
    string b = NumberToString (r);
    ll ans = r;

    for (int i = 0; i < (int) b.size(); i++) {
        if (b[i] == '0') {
            continue;
        }

        string curr = b;
        curr[i] = ( (curr[i] - '0') - 1) + '0';

        for (int j = i + 1; j < (int) curr.size(); j++) {
            curr[j] = '9';
        }

        ll num = 0;

        for (auto c : curr) {
            num = num * 10LL + (c - '0');
        }

        if (num >= l && digitProduct (ans) < digitProduct (num) ) {
            ans = num;
        }
    }

    return ans;
}

int main () {
    __FastIO;
    ll n;
    cin >> n;
    ll ans = findMaxNumber (1, n);
    cout << digitProduct (ans) << "\n";
    return 0;
}
