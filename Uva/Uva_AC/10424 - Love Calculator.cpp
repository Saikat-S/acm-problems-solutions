/***************************************************
 * Problem name : 10424 - Love Calculator.cpp
 * Problem Link : https://uva.onlinejudge.org/external/104/10424.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-08-04
 * Problem Type : String (Adhoc)
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
#define MAX 100000
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
int make_num(string str) {
    int sz = str.size(), sum = 0;
    for (int i = 0; i < sz; i++) {
        if (isalpha(str[i])) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = tolower(str[i]);
            }
            sum = sum + (str[i] - 'a' + 1);
        }
    }
    return sum;
}
int add(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int make_one(int n) {
    if (n <= 9) return n;
    while (n >= 10) {
        n = add(n);
    }
    return n;
}
int main () {
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        int aa = make_one(make_num(a));
        int bb = make_one(make_num(b));
        //~ printf("%d %d\n", aa, bb);
        double love;
        if (aa > bb) {
            love = (double)bb / (double)aa * 100.0;
        } else {
            love = (double)aa / (double)bb * 100.0;
        }
        printf("%.2lf %%\n", love);
    }
    return 0;
}

