/***************************************************
 * Problem name : 10935 Throwing cards away I.cpp
 * Problem Link : https://uva.onlinejudge.org/external/109/10935.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 03.06.2017
 * Problem Type : AdHoc
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
#define MAX 51
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
int main () {
    int N;
    vector<int>card, ans;
    while (scanf("%d", &N) == 1 && N != 0) {
        if (N == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: %d\n", N);
            continue;
        }
        for (int i = 1; i <= N; i++) {
            card.push_back(i);
        }
        for (int i = 0; i < N - 1; i++) {
            ans.push_back(card[0]);
            card.erase(card.begin() + 0);
            int x = card[0];
            card.erase(card.begin() + 0);
            card.push_back(x);
        }
        int x = card[0];
        int sz = ans.size();
        printf("Discarded cards:");
        for (int i = 0; i < sz; i++) {
            if (i == sz - 1) printf(" %d\n", ans[i]);
            else printf(" %d,", ans[i]);
        }
        printf("Remaining card: %d\n", x);
        ans.clear();
        card.clear();
    }
    return 0;
}

