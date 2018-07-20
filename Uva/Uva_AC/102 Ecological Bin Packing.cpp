/***************************************************
 * Problem name : 102 Ecological Bin Packing.cpp
 * Problem Link : https://uva.onlinejudge.org/external/1/102.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-12-21
 * Problem Type : AdHoc
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 100000
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int ar[15];
    map<int, string>mp;
    mp[1] = "BGC", mp[2]  = "BCG", mp[3] = "GBC", mp[4] = "GCB", mp[5] = "CBG", mp[6] = "CGB";
    //mp[1] = "BCG", mp[2]  = "BGC", mp[3] = "CBG", mp[4] = "CGB", mp[5] = "GBC", mp[6] = "GCB";
    while (scanf("%d", &ar[0]) == 1) {
        for (int i = 1 ; i < 9; i++) {
            scanf("%d", &ar[i]);
        }
        int arr[7];
        arr[1] = ar[1] + ar[2] + ar[3] + ar[5] + ar[6] + ar[7];
        arr[2] = ar[1] + ar[2] + ar[3] + ar[4] + ar[6] + ar[8];
        arr[3] = ar[0] + ar[2] + ar[4] + ar[5] + ar[6] + ar[7];
        arr[4] = ar[0] + ar[2] + ar[3] + ar[4] + ar[7] + ar[8];
        arr[5] = ar[0] + ar[1] + ar[4] + ar[5] + ar[6] + ar[8];
        arr[6] = ar[0] + ar[1] + ar[3] + ar[5] + ar[7] + ar[8];
        int  mn = arr[1], ans = 1;
        for (int i = 2; i <= 6; i++) {
            if (mn == arr[i]) {
                if (mp[ans] > mp[i]) {
                    mn = arr[i];
                    ans = i;
                }
            } else if (mn > arr[i]) {
                mn = arr[i];
                ans = i;
            }
        }
        cout << mp[ans] << " " << mn << "\n";
    }
    return 0;
}
