/***************************************************
 * Problem Name : Fibonacci Modified.cpp
 * Problem Link : https://www.hackerrank.com/challenges/fibonacci-modified/problem?h_r=next-challenge&h_v=zen
 * OJ           : HackerRank
 * Verdict      : TLE
 * Date         : 2019-01-21
 * Problem Type : dp
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
#define MAX 25
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
string add (string a, string b) {
    int al = (int) a.size() - 1;
    int bl = (int) b.size() - 1;
    int carry = 0;
    string result = "";

    while (al >= 0 && bl >= 0) {
        int temp = (int) (a[al] - '0') + (int) (b[bl] - '0') + carry ;
        carry = 0;

        if (temp > 9 ) {
            carry = 1;
            temp = temp - 10;
        }

        result += char (temp + '0');
        al--;
        bl--;
    }

    while (al >= 0) {
        int temp = (int) (a[al] - '0') + carry ;
        carry = 0;

        if (temp > 9) {
            carry = 1;
            temp = temp % 10;
        }

        result += char (temp + '0');
        al--;
    }

    while (bl >= 0) {
        int temp = (int) (b[bl] - '0') + carry ;
        carry = 0;

        if (temp > 9) {
            carry = 1;
            temp = temp % 10;
        }

        result += char (temp + '0');
        bl--;
    }

    if (carry) {
        result += "1";
    }

    reverse (result.begin(), result.end() );
    return result;
}
string trim (string a) {
    string res = "";
    int i = 0;

    while (a[i] == '0') {
        i++;
    }

    int sz = a.size();

    for (; i < sz; i++) {
        res += a[i];
    }

    return res;
}
string strmul (string s1, string s2) {
    string m, a;
    int i, l, l2, j, c, s = 0;
    reverse (s1.begin(), s1.end() );
    reverse (s2.begin(), s2.end() );

    if (s1.size() > s2.size() ) {
        swap (s1, s2);
    }

    l = s1.size();
    l2 = s2.size();
    j = 0;
    m = "", a = "";

    for (i = 0; i < l2; i++) {
        c = 0;
        m = "";

        for (j = 0; j < l; j++) {
            s = (s1[j] - '0') * (s2[i] - '0') + c;
            c = s / 10;
            m += (s % 10) + '0';
        }

        if (c > 0) {
            m += c % 10 + '0';
        }

        int k;
        reverse (m.begin(), m.end() );

        for (k = j; k < j + i; k++) {
            m += "0";
        }

        reverse (m.begin(), m.end() );

        if (i == 0) {
            a = m;
        }

        if (i != 0) {
            c = 0;
            reverse (a.begin(), a.end() );
            reverse (m.begin(), m.end() );
            a = (add (a, m) );
            reverse (a.begin(), a.end() );
        }
    }

    int flg = 0;

    for (i = 0; i < (int) a.size(); i++) {
        if (a[i] != '0') {
            flg = 1;
            break;
        }
    }

    if (flg == 0) {
        a = "0";
    }

    reverse (a.begin(), a.end() );
    return a;
}
string multiply (string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();

    if (n1 == 0 || n2 == 0)
        return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result (n1 + n2, 0);
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j = n2 - 1; j >= 0; j--) {
            // Take current digit of second number
            int n2 = num2[j] - '0';
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            // Carry for next iteration
            carry = sum / 10;
            // Store result
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;

    while (i >= 0 && result[i] == 0)
        i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
        return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += std::to_string (result[i--]);

    return s;
}
string fun (int n, string a, string b) {
    string c;

    for (int i = 3; i <= n; i++) {
        //~ string bb = strmul (b, b);
        string bb = multiply(b, b);
        c = (add (a, bb) );
        a = b;
        b = c;
    }

    return c;
}
int main () {
    //~ __FastIO;
    int n;
    string t1, t2;
    cin >> t1 >> t2 >> n;
    cout << fun (n, t1, t2 ) << "\n";
    return 0;
}
