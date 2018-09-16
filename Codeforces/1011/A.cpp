/***************************************************
 * Problem Name : A.cpp
 * Problem Link : http://codeforces.com/contest/1011/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-26
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
#define pb push_back
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<char>v;
    map<char, int>mp;
    int ii = 1;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        mp[ch] = ii++;
    }

    for (int i = 0; i < n; i++) {
        v.pb (str[i]);
    }

    sort (all (v) );
    int sum = 0, mn = 100000;

    for (int i = 0; i < n; i++) {
        char ch = v[i];
        int cnt = 1;
        sum = mp[ch];
        ch++;

        if (cnt >= k) {
            mn = min (mn, sum);
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            char c = ch;
            c--;

            if (ch != v[j] && v[j] != c) {
                sum += mp[v[j]];
                cnt++;
                ch = v[j];
                ch++;

                if (cnt >= k) {
                    mn = min (mn, sum);
                    break;
                }
            }
        }
    }

    if (mn == 100000) cout << "-1\n";
    else cout << mn << "\n";

    return 0;
}
