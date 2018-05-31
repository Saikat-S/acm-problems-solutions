/***************************************************
 * Problem Name : C - Club of Riders.cpp
 * Problem Link : https://www.codechef.com/problems/ZUBRIDER
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-05-25
 * Problem Type : Easy
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
#define MOD 1000000007
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
int flag ;
ll Lower(ll V[], ll n, ll value) {
    ll high = n, low = 1, ans = -1;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (V[mid] == value) {
            ans = mid;
            high = mid - 1;
        } else if (V[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == -1) {
        ans = high;
        flag = 1;
    }
    return ans;
}
int main () {
    int tc;
    ll Kp, Ks, N;
    cin >> tc;
    for(int t = 1; t<=tc; t++) {
        cin >> Kp>> Ks;
        cin >> N;
        ll ar[N+3];
        ll arr[N+3];
        for(int i = 1; i<=N; i++) {
            cin >> ar[i];
        }
        for(int i = 1; i<=N; i++) {
            cin >> arr[i];
        }
        ll sum = Kp * Ks;
        sort(ar+1, ar+N+1);
        sort(arr+1, arr+N+1);
        ll mx  = 1;
        for(int i = 1; i<=N; i++) {
            ll value = sum/ar[i];
            flag = 0;
            ll low = Lower(arr, N, value+1);
            if(flag == 1) {
                low = low+1;
            }
            ll x = ((N - low) + 1) - (i-1);
            mx = (mx * x)%MOD;
        }
        cout << "Case "<<t<<": "<<mx <<"\n";
    }
    return 0;
}
