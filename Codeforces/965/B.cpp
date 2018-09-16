/***************************************************
 * Problem name : B.cpp
 * OJ           :
 * Verdict      : Trying
 * Date         : 2018-04-25
 * Problem Type :
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
#define MAX 1005
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int n, k;
string str[MAX];
int c;
int checkL(int x, int j) {
    int c = 0;
    for (int i = x; i >= 0; i--) {
        if (str[i][j] == '.') c++;
        else {
            return c;
        }
    }
    return c;
}
int checkR(int x, int j) {
    int c = 0;
    for (int i = x; i < n; i++) {
        if (str[i][j] == '.') c++;
        else {
            return c;
        }
    }
    return c;

}
int checkU(int i, int y) {
    int c = 0;
    for (int j = y; j >= 0; j--) {
        if (str[i][j] == '.') c++;
        else {
            return c;
        }
    }
    return c;

}
int checkD(int i, int y) {
    int c = 0;
    for (int j = y; j < n; j++) {
        if (str[i][j] == '.') c++;
        else {
            return c;
        }
    }
     return c;

}
int main () {

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    int x = -1, y = -1;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i][j] == '.') {
                //~ debug;
                int cnt = 0;
                int l = checkL(i, j);
                //~ int cl = c;
                
                int r = checkR(i, j);
                //~ int cr = c;
                
                int u = checkU(i, j);
                //~ int cu = c;
                
                int d = checkD(i, j);
                //~ int cd = c;
                
                //~ printf("%d %d\n", l, r);  
                
                if (r>=k) {
                    cnt++;
                    if(l >= k-1){
                        cnt+=(k-2);
                    }
                    else{
                        int x = l - 1;
                        if( x>=0) cnt+=x;
                    }
                }
                if (l>=k) {
                    cnt++;
                    if(r >= k-1){
                        cnt+=(k-2);
                    }
                    else{
                        int x = r - 1;
                        if( x>=0) cnt+=x;
                    }
                }
                if (d>=k) {
                    cnt++;
                    if(u >=k-1){
                        cnt+=(k-2);
                    }
                    else{
                        int x = u - 1;
                        if( x>=0) cnt+=x;
                    }
                }
                if (u>=k){
                    cnt++;
                    if(d >=k-1){
                        cnt+=(k-2);
                    }
                    else{
                        int x = d - 1;
                        if( x>=0) cnt+=x;
                    }
                }

                //~ int cL = cl + cr;
                //~ int cU = cu + cd;

                //~ if (cL > k ) cnt++;
                //~ if (cU > k) cnt++;

                if (mx < cnt) {
                    mx = cnt;
                    x = i;
                    y = j;
                }
            }
        }
    }
    //~ printf("%d\n", mx);
    if (x == -1 && y == -1) printf("1 1\n");
    else printf("%d %d\n", ++x, ++y);

    return 0;
}
