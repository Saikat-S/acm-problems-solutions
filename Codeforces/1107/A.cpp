/***************************************************
 * Problem Name : A.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-26
 * Problem Type : Educational Round - A
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    //~ __FastIO;
    int q;
    cin >> q;

    while (q--) {
        int n;
        string str;
        cin >> n >> str;

        if (n == 2) {
            int a = str[0] - '0';
            int b = str[1] - '0';

            if (b > a) {
                cout << "YES\n";
                cout << 2 << "\n";
                cout << a << " " << b << "\n";

            } else {
                cout << "NO\n";
            }

        } else {
            int a  = str[0] - '0';
            int num = 0;
            int flag = 0;

            for (int i = 1; i < n; i++) {
                num = (num * 10) + (str[i] - '0');

                if (num > a) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                cout << "YES\n";
                cout << 2 << "\n";
                cout << str[0] << " ";

                for (int i = 1; i < n; i++) {
                    cout << str[i];
                }

                nl;

            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
