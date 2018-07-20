/***************************************************
 * Problem name : 497 Strategic Defense Initiative - 1.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/497.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 13.07.2017
 * Problem Type : LIS
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
#define MAX 10000
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
int L[MAX], I[MAX];
int LIS_NlogK(int n , vector<int>ar) {
    I[0] = -100000000;
    for (int i = 1; i <= n; i++) {
        I[i] = 100000000;
    }
    int Maxlen = 0;
    for (int i = 0; i < n; i++) {
        int low = 0, high = Maxlen, mid;
        while (high >= low) {
            mid = (low + high) / 2;
            if (I[mid] < ar[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        I[low] = ar[i];
        L[i] = low;
        if (Maxlen < low) {
            Maxlen = low;
        }
    }
    return Maxlen;
}
void LIS_Solution(int n, vector<int>ar) {
    vector<int>Sol;
    int i = 0;
    for (int j = 1 ; j < n; j++) {
        if (L[j] >= L[i]) {
            i = j;
        }
    }
    Sol.push_back(ar[i]);
    int top = i;
    for (int i = top - 1; i >= 0; i--) {
        if ( ar[i] < ar[top] && L[i] == L[top] - 1) {
            Sol.push_back(ar[i]);
            top = i;
        }
    }
    int sz = Sol.size();
    for (int i = sz - 1 ; i >= 0; i--) {
        printf("%d\n", Sol[i]);
    }
    Sol.clear();
}
int main () {
    int tc;
    vector<int>V;
    scanf("%d", &tc);
    getchar();
    getchar();
    for (int t = 1; t <= tc; t++) {
        string s;
        while (getline(cin, s)) {
            if (s.size() == 0) break;
            int num = 0, sz = s.size();
            for (int i = 0; i < sz; i++) {
                num = num * 10 + (s[i] - '0');
            }
            V.push_back(num);
        }
        int n = V.size();
        printf("Max hits: %d\n", LIS_NlogK(n, V));
        LIS_Solution(n, V);
        if (t != tc) nl;
        V.clear();
    }
    return 0;
}

