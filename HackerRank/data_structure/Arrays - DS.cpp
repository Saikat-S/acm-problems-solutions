/***************************************************
 * Problem Name : Arrays - DS.cpp
 * Problem Link : https://www.hackerrank.com/challenges/arrays-ds/problem
 * OJ           : HackerRank
 * Verdict      : Ac
 * Date         : 2019-06-25
 * Problem Type : Arrays
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
int *reverseArray (int a_count, int *a, int *result_count) {
    int *tmp = (int *) malloc (a_count * sizeof (int) );

    for (int i = 0, j = a_count - 1; j >= 0; i++, j--) {
        tmp[i] = a[j];
        result_count++;
    }

    return tmp;
}

int main() {
    //~ __FastIO;
    int n;
    scanf ("%d", &n);
    int *ar = (int *) malloc (n * sizeof (int) );

    for (int i = 0; i < n; i++) {
        scanf ("%d", &ar[i]);
    }

    int *arr = reverseArray (n, ar, 0);

    for (int i = 0; i < n; i++) {
        if (i != 0) printf (" ");

        printf ("%d", arr[i]);
    }

    return 0;
}
