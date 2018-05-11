/***************************************************
 * Problem name : 576 Haiku Review.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/576.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-27
 * Problem Type : AdHoc(String)
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
int main () {
    string str;
    int ar[4];
    map<char, int>mp;
    mp['a'] = 1, mp['e'] = 1, mp['i'] = 1, mp['o'] = 1, mp['u'] = 1, mp['y'] = 1;
    while (getline(cin, str)) {
        if(str == "e/o/i") break;
        SET(ar);
        int sz = str.size(), flag = 0, j = 0;
        for (int i = 0; i < sz; i++) {
            if (str[i] == '/') {
                j++;
                flag = 0;
            } else if (flag == 0 && mp[str[i]] == 1) {
                ar[j]++;
                flag = 1;
            }
            else if(flag == 1 && mp[str[i]] == 0){
                flag = 0;
            }
        }
        if(ar[0] == 5 && ar[1] == 7 && ar[2] == 5) printf("Y\n");
        else if(ar[0] != 5) printf("1\n");
        else if(ar[1] != 7) printf("2\n");
        else printf("3\n");
    }
    return 0;
}

