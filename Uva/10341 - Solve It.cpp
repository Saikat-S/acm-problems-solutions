/***************************************************
 * Problem name : 10341 - Solve if.cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 30-03-17
 * Problem Type : Binary Search
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define pii pair<int,int>
#define MAX 10000
using namespace std;
typedef long long ll;
double p, q, r, s, t, u, E;
double fun(double mid ) {
    return (p * exp(-1 * mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * mid * mid + u);
}
double BinarySearch() {
    double high = 1.1;
    double low = 0.0;
    double ans ;
    for (int i = 0; i < 200; i++) {
        double mid = (high + low) / 2.0;
        E = fun(mid);
        if (E >= 0.0000001) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    return ans;
}
int main () {
    while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6) {
        double ans = BinarySearch();
        if (fun(1) > 0.0000000001 || (p + r + u) < 0) {
            printf("No solution\n");
            continue;
        } else if (ans >= 0.0 && ans <= 1.0) {
            printf("%.4lf\n", ans);
        } else {
            printf("No solution\n");
        }
    }
    return 0;
}
