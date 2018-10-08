/***************************************************
 * Problem Name : PALIN - The Next Palindrome.cpp
 * Problem Link : https://www.spoj.com/problems/PALIN/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-08-08
 * Problem Type : AdHoc
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
int AreAll9s ( int *num, int n ) {
    int i;

    for ( i = 0; i < n; ++i ) {
        if ( num[i] != 9 ) {
            return 0;
        }
    }

    return 1;
}
void printArray (int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        cout << arr[i];
    }

    nl;
}
void generateNextPalindromeUtil (int num[], int n ) {
    int mid = n / 2;
    bool leftsmaller = false;
    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;

    while (i >= 0 && num[i] == num[j]) {
        i--, j++;
    }

    if ( i < 0 || num[i] < num[j]) {
        leftsmaller = true;
    }

    while (i >= 0) {
        num[j] = num[i];
        j++;
        i--;
    }

    if (leftsmaller == true) {
        int carry = 1;
        i = mid - 1;

        if (n % 2 == 1) {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;

        } else {
            j = mid;
        }

        while (i >= 0) {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--];
        }
    }
}
void generateNextPalindrome ( int num[], int n ) {
    int i;

    if ( AreAll9s ( num, n ) ) {
        cout << "1";

        for ( i = 1; i < n; i++ ) {
            cout << "0";
        }

        cout << "1\n";

    } else {
        generateNextPalindromeUtil ( num, n );
        printArray (num, n);
    }
}

int main () {
    __FastIO;
    int tc;
    string k;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> k;
        int n = (int) k.size();
        int ar[n + 5];

        for (int i = 0; i < n; i++) {
            ar[i] = k[i] - '0';
        }

        generateNextPalindrome (ar, n);
    }

    return 0;
}
