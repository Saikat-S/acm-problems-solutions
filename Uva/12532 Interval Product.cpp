/***************************************************
 * Problem name : 12532-Interval Product.cpp
 * Problem Link : https://uva.onlinejudge.org/external/125/12532.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-01
 * Problem Type : Sqrt Root Decomposition
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
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int ar[MAX];
int blockZ[MAX];
int blockN[MAX];
int blockSz;
void init(int sz) {
    for (int i = 0; i <= sz; i++) {
        blockZ[i] = 0;
        blockN[i] = 0;
    }
}
void update(int i, int value) {
    int id = i / blockSz;
    if (value < 0) {
        if (ar[i] == 0) {
            blockZ[id] -= 1;
            blockN[id] += 1;
        } else if (ar[i] > 0) {
            blockN[id] += 1;
        }
    } else if (value > 0) {
        if (ar[i] == 0) {
            blockZ[id] -= 1;
        } else if (ar[i] < 0) {
            blockN[id] -= 1;
        }
    } else {
        if (ar[i] < 0) {
            blockZ[id] += 1;
            blockN[id] -= 1;
        } else if (ar[i] > 0) {
            blockZ[id] += 1;
        }
    }
    ar[i] = value;
}
int query(int L, int R) {
    int l = L / blockSz;
    int  r = R / blockSz;
    int n = 0, z = 0;
    if (l == r) {
        for (int i = L; i <= R; i++) {
            if (ar[i] == 0) z++;
            else if (ar[i] < 0) n++;
        }
        int P;
        if ( z > 0 ) P = 0;
        else if (n % 2 == 1) P = -1;
        else P = 1;
        return P;
    }
    for (int i = L; i < (l + 1)*blockSz; i++) {
        if (ar[i] == 0) z++;
        else if (ar[i] < 0) n++;
    }
    for (int i = l + 1; i < r; i++) {
        z += blockZ[i];
        n += blockN[i];

    }
    for (int i = r * blockSz; i <= R; i++) {
        if (ar[i] == 0) z++;
        else if (ar[i] < 0) n++;
    }
    int P;
    if ( z > 0 ) P = 0;
    else if (n % 2 == 1) P = -1;
    else P = 1;
    return P;
}
int main () {
    int N, Q;
    while (scanf("%d %d", &N, &Q) == 2) {
        blockSz = sqrt(N);
        init(blockSz);
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            if (x > 0) ar[i] = 1;
            else if (x == 0) ar[i] = 0;
            else ar[i] = -1;
            if(ar[i] == 0){
                blockZ[i/blockSz]+=1;
            }
            else if(ar[i] < 0){
                blockN[i/blockSz]+=1;
            }
        }
        for (int q = 1; q <= Q; q++) {
            char ch;
            cin >> ch;
            if (ch == 'C') {
                int i;
                int value;
                scanf("%d %d", &i, &value);
                if (value > 0) value = 1;
                else if (value == 0) value = 0;
                else value = -1;
                update(i - 1, value );
            } else {
                int l, r;
                scanf("%d %d", &l, &r);
                //~ printf("%lld %lld\n", l, r);
                int ans  = query(l - 1, r - 1);
                //~ printf("%lld\n", ans);
                if (ans > 0) printf("+");
                else if (ans == 0)printf("0");
                else printf("-");
            }

        }
        nl;
    }

    return 0;
}
