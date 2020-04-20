#include <iostream>
using namespace std;
typedef long long ll;
/************************************ Code Start Here ******************************************************/

ll bigMod (ll a, ll b, ll MOD) {
    ll res = 1;

    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    int tc;
    cin >> tc;

    while (tc--) {
        ll a, b;
        cin >> a >> b;
        cout << bigMod (a, b, 10) << '\n';
    }

    return 0;
}
