/***************************************************
 * Problem Name : 1214 - Large Division.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1214
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-10-03
 * Problem Type : Big Integer
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
struct Bigint {
    string a;
    int sign;

    Bigint() {}
    Bigint ( string b ) {
        (*this) = b;
    }

    int size() {
        return a.size();
    }
    Bigint inverseSign() {
        sign *= -1;
        return (*this);
    }
    Bigint normalize ( int newSign ) {
        for ( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
            a.erase (a.begin() + i);

        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }

    void operator = ( string b ) {
        a = b[0] == '-' ? b.substr (1) : b;
        reverse ( a.begin(), a.end() );
        this->normalize ( b[0] == '-' ? -1 : 1 );
    }

    bool operator < ( const Bigint &b ) const {
        if ( sign != b.sign ) return sign < b.sign;

        if ( a.size() != b.a.size() )
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();

        for ( int i = a.size() - 1; i >= 0; i-- ) if ( a[i] != b.a[i] )
                return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];

        return false;
    }
    bool operator == ( const Bigint &b ) const {
        return a == b.a && sign == b.sign;
    }
    Bigint operator + ( Bigint b ) {
        if ( sign != b.sign ) return (*this) - b.inverseSign();

        Bigint c;

        for (int i = 0, carry = 0; i < (int) a.size() || i <  (int) b.size()
             || carry; i++ ) {
            carry += (i <  (int) a.size() ? a[i] - 48 : 0) + (i <  (int) b.a.size() ?
                     b.a[i] - 48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }

        return c.normalize (sign);
    }
    Bigint operator - ( Bigint b ) {
        if ( sign != b.sign ) return (*this) + b.inverseSign();

        int s = sign; sign = b.sign = 1;

        if ( (*this) < b ) return ( (b - (*this) ).inverseSign() ).normalize (-s);

        Bigint c;

        for ( int i = 0, borrow = 0; i < (int) a.size(); i++ ) {
            borrow = a[i] - borrow - (i < (int) b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }

        return c.normalize (s);
    }
    Bigint operator * ( Bigint b ) {
        Bigint c ("0");

        for ( int i = 0, k = a[i] - 48; i < (int) a.size(); i++, k = a[i] - 48 ) {
            while (k--) c = c + b;

            b.a.insert (b.a.begin(), '0');
        }

        return c.normalize (sign * b.sign);
    }
    Bigint operator / ( Bigint b ) {
        if ( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Bigint c ("0"), d;

        for ( int j = 0; j < (int) a.size(); j++ ) d.a += "0";

        int dSign = sign * b.sign; b.sign = 1;

        for ( int i = (int) a.size() - 1; i >= 0; i-- ) {
            c.a.insert ( c.a.begin(), '0');
            c = c + a.substr ( i, 1 );

            while ( ! ( c < b ) ) c = c - b, d.a[i]++;
        }

        return d.normalize (dSign);
    }
    Bigint operator % ( Bigint b ) {
        if ( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Bigint c ("0");
        b.sign = 1;

        for ( int i = a.size() - 1; i >= 0; i-- ) {
            c.a.insert ( c.a.begin(), '0');
            c = c + a.substr ( i, 1 );

            while ( ! ( c < b ) ) c = c - b;
        }

        return c.normalize (sign);
    }
    void print (int t) {
        if (a[a.size() - 1] == '0') printf ("Case %d: divisible\n", t);
        else printf ("Case %d: not divisible\n", t);
    }
};
int main () {
    //~ __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        Bigint a, b, c;
        string input;
        cin >> input;
        a = input;
        cin >> input;
        b = input;
        c = a % b;
        c.print (t);
    }

    return 0;
}
