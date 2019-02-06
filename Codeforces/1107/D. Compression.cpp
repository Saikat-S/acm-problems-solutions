/***************************************************
 * Problem Name : D. Compression.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-01-26
 * Problem Type :
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
#define MAX 5205
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
string hex_char_to_bin (char c) {
    switch (toupper (c) ) {
        case '0': return "0000";

        case '1': return "0001";

        case '2': return "0010";

        case '3': return "0011";

        case '4': return "0100";

        case '5': return "0101";

        case '6': return "0110";

        case '7': return "0111";

        case '8': return "1000";

        case '9': return "1001";

        case 'A': return "1010";

        case 'B': return "1011";

        case 'C': return "1100";

        case 'D': return "1101";

        case 'E': return "1110";

        case 'F': return "1111";
    }

    return 0;
}

string hex_to_bin (string hex) {
    string bin;

    for (int i = 0; i != (int) hex.length(); i++) {
        bin += hex_char_to_bin (hex[i]);
    }

    return bin;
}
int main () {
    //~ __FastIO;
    int n;
    string str[MAX], mat[MAX];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    debug;

    for (int i = 0; i < n; i++) {
        mat[i] = hex_to_bin (str[i]);
        cout << mat[i] << "\n";
    }

    return 0;
}
