/***************************************************
 * Problem Name : D - Triangle Count.cpp
 * Problem Link : https://www.codechef.com/problems/ZUBTRCNT
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-05-25
 * Problem Type : Beginner
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
int main() {
    int n, m ;
    int t ;
    cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) {
        cin >> n >> m ;
        int cnt = 0 ;
        m+=1 ;
        int point = n+1 ;
        while( point >= m ) {
            cnt += ( point-m+1 ) ;
            point-- ;
        }
        cout << "Case " << i <<": " <<  cnt << endl;
    }
    return 0;
}
