#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int n;
    cin >> n;
    int ar[n + 3];

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }


    int mn = 1000000000;

    for (int j = 1; j <= n; j++) {
        int sum = 0;
        int x = j;

        for (int i = 1; i <= n; i++) {
            int xx = abs (x - i);
            xx += (i - 1);
            xx += (x - 1);
            xx += (x - 1);
            xx += (i - 1);
            xx += abs (x - i);
            sum += (xx * ar[i]);
        }

        mn = min (mn, sum);
    }

    cout << mn << "\n";
    return 0;
}

