/***************************************************
 * Problem Name : B. Queue at the School.cpp
 * Problem Link : http://codeforces.com/contest/266/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-05-21
 * Problem Type : B
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int n, x;
    string str;
    cin >> n >> x;
    cin >> str;
    for(int i = 1; i<=x; i++) {
        string s = str;
        for(int j = 0; j<n-1;) {
            if(s[j] == 'B' && s[j+1] == 'G') {
                s[j] = 'G';
                s[j+1] = 'B';
                j+=2;
            }else j++;
        }
        str = s;
    }
    cout << str<<"\n";
    return 0;
}
