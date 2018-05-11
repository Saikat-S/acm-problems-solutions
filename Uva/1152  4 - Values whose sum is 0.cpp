/***************************************************
 * Problem name : 1152  4 - Values whose sum is 0.cpp
 * OJ           : Uva
 * Verdict      : Accepted
 * Date         : 31.05.2017
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
//~ #define MAX 33554433
#define MAX 16000001
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

int flag ;
int LowerBound(int ar[], int n, int value) {
    int high = n - 1;
    int low = 0;
    int ans = -1;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (ar[mid] == value) {
            ans = mid;
            high = mid - 1;
        } else if (ar[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == -1) {
        flag = 1;
        ans = high;
    }
    return ans + 1;
}
int UpperBound(int ar[], int n, int value) {
    int high = n - 1;
    int ans, low = 0;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (ar[mid] == value) {
            ans = mid;
            low = mid + 1;
        } else if (ar[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans + 1;
}
int main () {
    int A[MAX], B[MAX], C[MAX], D[MAX];
    int a[MAX], b[MAX];
    int tc, n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[k] = A[i] + B[j];
                b[k] = C[i] + D[j];
                k++;
            }
        }
        sort(b, b + k);
        int sum = 0;
        for (int i = 0; i < k; i++) {

            int x = a[i] * -1;
            flag = 0;
            int l = LowerBound(b, k, x);
            if (flag == 0) {
                int u = UpperBound(b, k, x);
                int ans = (u - l) + 1;
                sum = sum + ans;
            }

        }
        printf("%d\n", sum);
        if(t!=tc) printf("\n");
    }

    return 0;
}

