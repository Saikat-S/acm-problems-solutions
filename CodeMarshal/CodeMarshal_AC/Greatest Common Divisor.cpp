/***************************************************
 * Problem Name : Greatest Common Divisor.cpp
 * Problem Link : http://algo.codemarshal.org/problems/556cb2392251f00300a82f41
 * OJ           : CodeMarshal
 * Verdict      : AC
 * Date         : 2018-07-25
 * Problem Type : Nubmer Theory(gcd)
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main () {
    int a, b;
    cin >> a >> b;
    cout << __gcd (a, b) << "\n";
    return 0;
}
