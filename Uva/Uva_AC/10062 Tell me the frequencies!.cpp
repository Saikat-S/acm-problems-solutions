/***************************************************
 * Problem name : 10062 Tell me the frequencies!.cpp
 * Problem Link : https://uva.onlinejudge.org/external/100/10062.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-27
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
#define pii pair<int,int>
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
bool compare(st a, st b) {
    if (a.num == b.num) return a.ch > b.ch;
    else return a.num < b.num;
}
int main () {
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    string str;
    int mp[MAX], t = 0;
    //~ map<char, int>mp;
    while (getline(cin,str)) {
        SET(mp);
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            mp[str[i]]++;
        }
        st ar[MAX];
        int j = 0;
        for (int i = 32; i <= 128; i++) {
            if (mp[i] != 0 ) {
                ar[j].ch = i;
                ar[j].num = mp[i];
                j++;
            }
        }
        sort(ar, ar + j, compare);
        if(t)  nl;
        t++;
        for (int i = 0; i < j; i++) {
            printf("%d %d\n", ar[i].ch, ar[i].num);
        }
        //~ mp.clear();
    }
    return 0;
}

