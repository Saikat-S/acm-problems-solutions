/***************************************************
 * Problem name : 12856 Counting substhreengs.cpp
 * Problem Link : https://uva.onlinejudge.org/external/128/12856.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : String
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
#define nl printf("\n")
#define sp printf(" ")
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
string str;

ll slide(int st, int end) {
    ll C[5];
    ll sum = 0, mod;
    SET(C, 0);
    ll cnt = 0;
    for (int i = st; i <= end; i++) {
        ll x = str[i] - '0';
        sum += x;
        mod  = sum % 3;
        if (mod == 0) cnt++;
        ll xx = C[mod];
        cnt += xx;
        C[mod]++;
    }
    return cnt;
}

int main () {
    __FastIO;

    while (cin >> str) {
        ll cnt  = 0;
        for (int i = 0; i < (int) str.size(); i++) {
            if (isdigit(str[i])) {
                for (int j = i; j < (int) str.size(); j++) {
                    if (!isdigit(str[j])) {
                        ll tmp = slide(i, j - 1);
                        cnt += tmp;
                        i = j;
                        break;
                    } else if (isdigit(str[j]) and j == (int) str.size() - 1) {
                        ll tmp = slide(i, j);
                        cnt += tmp;
                        i = j;
                        break;
                    }
                }

            }
        }
        cout << cnt << '\n';
        str.clear();
    }

    return 0;
}
