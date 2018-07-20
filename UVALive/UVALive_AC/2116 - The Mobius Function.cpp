/***************************************************
 * Problem name : 2116 - The Mobius Function.cpp
 * Problem Link : https://icpcarchive.ecs.baylor.edu/external/21/2116.pdf
 * OJ           : UvaLive
 * Verdict      : AC
 * Date         : 2017-10-24
 * Problem Type : Number Theory(MobiusFunction)
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
#define MAX 10005
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
int prime[MAX], ar[MAX], MF[MAX], pSize;
void sieve() {
    ar[0] = -1, ar[1] = -1;
    int sqrtMAX = sqrt(MAX);
    for (int i = 2; i <= sqrtMAX; i++) {
        if (ar[i] == 0) {
            for (int j = i + i; j <= MAX; j += i) {
                ar[j] = -1;
            }
        }
    }
    pSize = 0;
    for (int i = 1; i <= MAX; i++) {
        if (ar[i] == 0) {
            prime[pSize++] = i;
        }
    }
}
int Mobius_Function(int n, int &f) {
    int sqrtN = sqrt(n);
    int cnt = 0;
    for (int i = 0; i <= sqrtN; i++) {
        if (!(n % prime[i])) {
            cnt++;
            n /= prime[i];
            while (!(n % prime[i])) {
                cnt++;
                f++;
                n /= prime[i];
            }
        }
    }
    if (n > 1) {
        cnt++;
    }
    return cnt;
}
int main () {
    sieve() ;
    int n, t = 0;
    while (scanf("%d", &n) == 1 && n != -1) {
        int f = 0, ans;
        int cnt = Mobius_Function(n, f);
        if (f != 0) ans = 0;
        else {
            if (cnt % 2 == 0) ans = 1;
            else ans = -1;
        }
        if (t != 0) nl;
        printf("M(%d) = %d\n", n, ans);
        t++;
    }
    return 0;
}

