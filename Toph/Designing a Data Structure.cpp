/***************************************************
 * Problem name : Designing a Data Structure.cpp
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2018-03-22
 * Problem Type : Data Structure
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl cout << "\n"
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 1000006
#define INF 1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
ll fun(deque<ll>dq, int x) {
    ll ans;
    if ( x == 1) {
        ans = 0;
        while(!dq.empty()){
            ans = max(ans, dq.front());
            dq.pop_front();
        }
    }
    else{
        ans = 1000005;
        while(!dq.empty()){
            ans = min(ans, dq.front());
            dq.pop_front();
        }
    }
    return ans;
}
int main () {
	__FastIO;
    int n;
    ll X;
    string a, b;
    cin >> n;
    deque<ll>dq;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == "Insert") {
            cin >> X;
            if ( b == "Back") {
                dq.push_back(X);
            } else {
                dq.push_front(X);
            }
        } else if ( a == "Erase") {
            if ( b == "Front") {
                dq.pop_front();
            } else {
                dq.pop_back();
            }
        } else if (a == "Get") {
            if ( b == "Front") {
                cout <<  dq.front(); nl;
            } else if (b == "Back") {
                cout <<  dq.back(); nl;
            } else if (b == "Max") {
                cout << fun(dq, 1); nl;
            } else if (b == "Min") {
                cout << fun(dq, 2); nl;
            }
        }
    }
    return 0;
}
