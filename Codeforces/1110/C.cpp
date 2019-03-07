/***************************************************
 * Problem Name : C.cpp
 * Problem Link : https://codeforces.com/contest/1110/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-02-07
 * Problem Type : CGR - C
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
vector<int>num;
ll sz;
map<ll, ll>mp;

bool isPowerOfTwo (ll n) {
    return (ceil (log2 (n) ) == floor (log2 (n) ) );
}
void solve (ll N) {
    num.clear();

    while (N > 0) {
        int rem = N % 2;
        num.pb (rem);
        N /= 2;
    }

    reverse (all (num) );
    sz = (int) num.size();
}
ll P (ll x) {
    if (x  == 0) return 1;

    ll nm = 1;

    for (int i = 1; i <= x; i++) {
        nm = 2LL * nm;
    }

    return nm;
}
//~ void print (ll n) {
//~ solve (n);
//~ cout << n << " : ";

//~ for (int i = 0; i < sz; i++) {
//~ cout << num[i] << " ";
//~ }

//~ nl;
//~ }

//~ ll fun (ll T) {
//~ ll mx = 0;

//~ for (int i = 1; i < T; i++) {
//~ ll gc = __gcd ( (T xor i), (T & i) );
//~ mx = max (mx, gc);
//~ }

//~ return mx;
//~ }

void fun1 (ll a) {
    if (isPowerOfTwo (a + 1) == false) {
        solve (a);
        ll b = 0;

        for (int i = 0; i < sz; i++) {
            if (num[i] == 0) {
                //~ cout << i << " c\n";
                b += (P (sz - i - 1LL) );
            }
        }

        cout << (a xor b) << "\n";
    }
}

void preCal() {
    mp[3] = 1, mp[7] = 1, mp[15] = 5, mp[31] = 1, mp[63] = 21;
    mp[127] = 1, mp[255] = 85, mp[511] = 73, mp[1023] = 341;
    mp[63] = 21, mp[2047] = 89, mp[4095]  = 1365;
    mp[8191]  = 1, mp[16383]  = 5461, mp[32767]  = 4681;
    mp[65535]  = 21845, mp[131071] = 1, mp[262143] = 87381, mp[524287]  = 1;
    mp[1048575]  = 349525;
    mp[2097151] = 299593, mp[4194303] = 1398101, mp[8388607]  = 178481;
    mp[16777215] =  5592405, mp[33554431]  = 1082401;
}

int main () {
    __FastIO;
    preCal();
    int q;
    ll a;
    cin >> q;

    while (q--) {
        cin >> a;

        if (mp[a] != 0) {
            cout << mp[a] << "\n";

        } else {
            fun1 (a);
        }
    }

    return 0;
}
