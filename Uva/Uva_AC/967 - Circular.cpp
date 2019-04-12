/***************************************************
 * Problem Name : 967 - Circular.cpp
 * Problem Link : https://uva.onlinejudge.org/external/9/967.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-04-02
 * Problem Type : Number Theory
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
#define MAX 1000005
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
vector<int>prime;
char isPrime[MAX];
int sum[MAX];
void seivePrime (int n) {
    isPrime[0] = 1, isPrime[1] = 1;

    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = 1;
    }

    int sq = sqrt (n);

    for (int i = 3; i <= sq; i += 2) {
        if (isPrime[i] == 0) {
            for (int j = i * i ; j <= n; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}
int stringToNum (string str) {
    int num  = 0;
    int sz = str.size();

    for (int i = 0; i < sz; i++) {
        num = (num * 10) + (str[i] - '0');
    }

    return num;
}
string getNum (string n) {
    string str;

    for (int i = 1; i < (int) n.size(); i++) {
        str.pb (n[i]);
    }

    str.pb (n[0]);
    return  str;
}

bool isCurcular (int n) {
    string s = NumberToString (n);

    if (isPrime[n] == 1) return false;

    for (int i = 1; i < (int) s.size(); i++) {
        s = getNum (s);
        int num = stringToNum (s);

        if (isPrime[num] == 1) return false;
    }

    return true;
}

void preCal() {
    sum[100] = 0;

    for (int i = 101; i < MAX; i++) {
        if (isPrime[i] == 0 && isCurcular (i) ) {
            sum[i] = sum[i - 1] + 1;

        } else {
            sum[i] = sum[i - 1];
        }
    }
}

int main () {
    __FastIO;
    seivePrime (MAX - 2);
    preCal();
    int l, r;

    while (cin >> l) {
        if (l == -1) break;

        cin >> r;
        int ans = sum[r] - sum[l - 1];

        if (ans == 0) {
            cout << "No Circular Primes.\n";

        } else if (ans == 1) {
            cout << "1 Circular Prime.\n";

        } else {
            cout << ans << " Circular Primes.\n";
        }
    }

    return 0;
}
