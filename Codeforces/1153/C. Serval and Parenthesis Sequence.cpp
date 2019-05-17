/***************************************************
 * Problem Name : C. Serval and Parenthesis Sequence.cpp
 * Problem Link : https://codeforces.com/contest/1153/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-18
 * Problem Type : Div 2 - C
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MOD 1000000007
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
    __FastIO;
    int n;
    string str;
    cin >> n;
    cin >> str;

    if (n % 2 == 1) {
        cout << ":(\n";
        exit (0);
    }

    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') a++;
        else if (str[i] == ')') b++;
    }

    a = n / 2 - a;
    b = n / 2 - b;
    vector<int>vec;

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            vec.pb (1);

        } else if (str[i] == ')') {
            vec.pb (-1);

        } else {
            if (a != 0) {
                vec.pb (1);
                a--;

            } else if (b != 0) {
                vec.pb (-1);
                b--;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += vec[i];

        if ( (i < n - 1 && sum == 0) || sum < 0) {
            cout << ":(\n";
            exit (0);
        }
    }

    if (sum != 0) {
        cout << ":(\n";

    } else {
        for (int i = 0; i < n; i++) {
            if (vec[i] == 1) {
                cout << "(";

            } else if (vec[i] == -1) {
                cout << ")";
            }
        }

        nl;
    }

    return 0;
}
