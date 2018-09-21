/***************************************************
 * Problem Name : F. Bakkar In The Army.cpp
 * Problem Link : https://codeforces.com/gym/100283/problem/F
 * OJ           : Codeforces Gym
 * Verdict      : AC
 * Date         : 2018-09-21
 * Problem Type : Binary Search
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
#define MAX 1542250
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
/************************************ Code Start Here ******************************************************/
ll ar[MAX], sum[MAX], mp[MAX];
ll n;
void preCal() {
    sum[0] = 0;
    mp[0] = 0;

    for (n = 1; ; n++) {
        if (n == 1)  sum[n] = 1;
        else if (n == 2) sum[n] = 5;
        else {
            ll s1 = (n * (n + 1) ) / 2;
            ll nn = n - 1;
            ll s2 = (nn * (nn + 1) ) / 2;
            ll s = s1 + s2;
            sum[n] = sum[n - 1] + s;
        }

        mp[n] = mp[n - 1] + ( (n * 2) - 1);

        if (sum[n] > 1000000000000000000) break;
    }
}
ll nTh (ll sm) {
    ll NN = 8LL * sm + 1LL;
    NN = sqrt (NN) - 1LL;
    NN /= 2LL;
    ll SM = (NN * ( NN + 1LL ) ) / 2LL;

    if (SM < sm) NN++;

    return NN;
}

ll nTH (ll sm) {
    ll NN = 8LL * sm + 1LL;
    NN = sqrt (NN) - 1LL;
    NN /= 2LL;
    return NN;
}
int main () {
    __FastIO;
    freopen ("army.in", "r", stdin);
    preCal();
    int tc;
    ll N;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> N;
        ll lw = lower_bound (sum, sum + n, N) - sum;
        ll cnt = mp[lw - 1];
        ll ans = sum[lw - 1];
        ll X = N - ans;
        ll XX = (lw * (lw + 1) ) / 2;

        if (XX >= X) {
            ll x = nTh (X);
            cnt += x;

        } else {
            cnt += lw;
            X = X - XX;
            ll SS = ( (lw - 1) * (lw) ) / 2;
            SS = SS - X;
            ll xx = nTH (SS);
            cnt += ( (lw - 1 ) - xx);
        }

        cout << "Case " << t << ": " << cnt << "\n";
    }

    return 0;
}
