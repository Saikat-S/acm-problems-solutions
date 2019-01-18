#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binary (ll mn, ll n, ll s, ll sum) {
    ll low = 0, high = mn;
    ll mid, ans;

    while (high >= low) {
        mid = (high + low) / 2;
        ll x = mid * n;
        ll xx = sum - x;

        if (xx >= s) {
            low = mid + 1;
            ans = mid;

        } else {
            high = mid - 1;
        }
    }

    return ans;
}
int main () {
    ll n, s;
    cin >> n >> s;
    ll ar[n + 3];
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }

    if (sum < s) {
        cout << "-1\n";

    } else {
        sort (ar, ar + n);
        ll mn = ar[0];
        cout << fun (mn, n, s, sum) << "\n";
    }

    return 0;
}

