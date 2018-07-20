/***************************************************
 * Problem name : 424  Integer Inquiry.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/424.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-07-23                         
 * Problem Type : string sum                               
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
#define MAX 103
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
string add(string a, string b) {
    int al = a.size() - 1;
    int bl = b.size() - 1;

    int carry = 0;
    string result = "";

    while (al >= 0 && bl >= 0) {
        int temp = (int)(a[al] - '0') + (int)(b[bl] - '0') + carry ;
        carry = 0;
        if (temp > 9 ) {
            carry = 1;
            temp = temp - 10;
        }
        result += char(temp + '0');
        al--;
        bl--;
    }
    while (al >= 0) {
        int temp = (int)(a[al] - '0') + carry ;
        carry = 0;
        if (temp > 9) {
            carry = 1;
            temp = temp % 10;
        }

        result += char(temp + '0');
        al--;
    }
    while (bl >= 0) {
        int temp = (int)(b[bl] - '0') + carry ;
        carry = 0;
        if (temp > 9) {
            carry = 1;
            temp = temp % 10;
        }
        result += char(temp + '0');
        bl--;
    }
    if (carry) {
        result += "1";
    }

    string addition = "";

    //~ for (int i = result.size() - 1; i >= 0; i--) {
        //~ addition += result[i]; // reversing the answer
    //~ }
    //~ return addition; 
    reverse(result.begin(), result.end());
    return result;
}
string trim(string a) { // for removing leading 0s
    string res = "";
    int i = 0;

    while (a[i] == '0'){
        i++;
	}
    int sz = a.size();
    for (; i < sz; i++){
        res += a[i];
    }
    return res;
}
int main () {
    string s, ans="";
    while(cin>>s){
        if(s[0] == '0' && s.size() == 1) break;
        ans = trim(add(ans, s));
    }
    cout << ans;
    nl;
    return 0;
}

