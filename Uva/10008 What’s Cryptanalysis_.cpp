/***************************************************
 * Problem name : 10008 What’s Cryptanalysis?.cpp
 * Problem Link : https://uva.onlinejudge.org/external/100/10008.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-26
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
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,char>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 260
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
struct st {
    int ch;
    int num;
};
bool compare(st x, st y) {
    if (x.num == y.num) return x.ch < y.ch;
    else return x.num > y.num;
}
int main () {
    int n;
    string str;
    int mp[MAX];
    scanf("%d", &n);
    getchar();
    SET(mp);
    for (int l = 1; l <= n; l++) {
        getline(cin, str);
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            if (isalpha(str[i])) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] = toupper(str[i]);
                }
                mp[str[i]]++;
            }
        }
        //~ cout << str;
    }
    st ar[27];
    int j = 0;
    for (int i = 65; i <= 91; i++) {
        if (mp[i] != 0) {
            ar[j].ch = i;
            ar[j].num = mp[i];
            j++;
            //~ printf("%c %d\n", i, mp[i]);
        }
    }
    sort(ar, ar + j, compare);
    for (int i = 0; i < j; i++) {
        printf("%c %d\n", ar[i].ch, ar[i].num);
    }
    return 0;
}

