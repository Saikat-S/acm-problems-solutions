#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;
int main () {
    int n;
    cin >> n;

    if (n <= 2) cout << "No\n";
    else {
        cout << "Yes\n";

        if (n % 2 == 1) {
            cout << "1 " << (n / 2 + 1) << "\n";
            cout << n - 1 << " ";

            for (int i = 1; i <= n; i++) {
                if (i != (n / 2 + 1) ) cout << i << " ";
            }

        } else {
            cout << "1 " << n / 2 << "\n";
            cout << n - 1 << " ";

            for (int i = 1; i <= n; i++) {
                if (i != (n / 2) ) cout << i << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}

