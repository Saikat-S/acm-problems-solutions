/***************************************************
 * Problem name : 11239 Open Source.cpp
 * Problem Link : https://uva.onlinejudge.org/external/112/11239.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-24
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
#define pii pair<int,string>
#define pll pair <string, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 103
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
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    string str;
    map<int, string>mp;
    map<string, int>user, chk;
    while (1) {
        int k = 1, ar[MAX];
        SET(ar);
        while (getline(cin, str)) {
            if (str[0] == '0' && str.size() == 1) return 0;
            if (str[0] == '1' && str.size() == 1) break;
            if (str[0] >= 'A' && str[0] <= 'Z') {
                mp[k++] = str;
            } else {
                if (user[str] == 0) {
                    ar[k - 1]++;
                    user[str] = 1;
                    chk[str] = k - 1;
                } else {
                    if (chk[str] != k - 1 && user[str] != 2) {
                        ar[chk[str]]--;
                        user[str] = 2;
                    }
                }
            }
        }
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (ar[j] > ar[i]) {
                    int tmp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = tmp;

                    string tm = mp[i];
                    mp[i] = mp[j];
                    mp[j] = tm;
                } else if (ar[j] == ar[i]) {
                    if (mp[i] > mp[j]) {
                        int tmp = ar[i];
                        ar[i] = ar[j];
                        ar[j] = tmp;

                        string tm = mp[i];
                        mp[i] = mp[j];
                        mp[j] = tm;
                    }
                }
            }
        }
        for (int i = 1; i < k; i++) {
            cout << mp[i] << " " << ar[i] << "\n";
        }
        mp.clear(), user.clear(), chk.clear();
    }
    return 0;
}

