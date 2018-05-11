/***************************************************
 * Problem name : 10611 The Playboy Chimp - 1.cpp
 * Problem Link : https://uva.onlinejudge.org/external/106/10611.pdf
 * OJ           : Uva
 * Verdict      : AC(Time = 1230ms)
 * Date         : 13.06.2017
 * Problem Type : AdHoc use Binary Search
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 50005
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/************************************ Code Start Here ******************************************************/
ull n, ar[MAX], flag;
ull LowerBound(ull x) {
    ull low = 0, high = n - 1, ans = 0;
    while (high >= low) {
        ull mid = (high + low) / 2;
        if (ar[mid] == x) {
            ans = mid;
            high = mid - 1;
        } else if (ar[mid] > x) {
            high = mid - 1;
        } else {
            //ans = mid;
            low = mid + 1;
        }
    }
    if (ans == 0) {
        flag = 1;
        ans = high;
    }
    return ans;
}
ull BinarySearch(ull value) {
    ull mid, high = n - 1, low = 0, ans = 0;
    while (high >= low) {
        mid = (high + low) / 2;
        if (ar[mid] == value) {
            ans = mid;
            low = mid + 1;
        } else if (ar[mid] > value) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == 0) {
        ans = low;
        flag = 1;
    }
    return ans;
}
int main () {
    ull Q, x;
    scanf("%llu", &n);
    for (ull i = 0; i < n ; i++) scanf("%llu", &ar[i]);
    scanf("%llu", &Q);
    sort(ar, ar + n);
    for (ull q = 1; q <= Q; q++) {
        scanf("%llu", &x);
        ull mn, mx;
        flag = 0;
        if (x == ar[n - 1]) {
            mn = LowerBound(x);
            if (flag == 1) {
                printf("%llu X\n", ar[mn]);
            } else {
                printf("%llu X\n", ar[mn - 1]);
            }

        } else if ( x > ar[n - 1]) {
            mn = ar[n - 1];
            printf("%llu X\n", mn);
        } else if (x == ar[0]) {
            mx = BinarySearch(x);
            if (flag == 1) {
                printf("X %llu\n", ar[mx]);
            } else {
                printf("X %llu\n", ar[mx - 1]);
            }
        } else if (x < ar[0]) {
            mx = ar[0];
            printf("X %llu\n",mx);
        } else {
            mn = LowerBound(x);
            if (flag == 1) mn = mn;
            else mn = mn - 1;
            flag = 0;
            mx = BinarySearch(x);
            cout << mx;
            nl;
            if (flag == 1) mx = mx;
            else mx = mx + 1;

            printf("%llu %llu\n", ar[mn], ar[mx]);

        }
    }
    return 0;
}
