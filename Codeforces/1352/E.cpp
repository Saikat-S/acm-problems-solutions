/***************************************************
 * Problem Name : E.cpp
 * Problem Link : https://codeforces.com/contest/1352/problem/E
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-05-09
 * Problem Type : Div/Edu -
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int>vec (n);
        bool ar[n + 3];

        for (int i = 0; i <= n; i++) {
            ar[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int sum = vec[i];

            for (int j = i + 1; j < n; j++) {
                sum += vec[j];

                if (sum > n) break;

                ar[sum] = 1;
            }
        }

        for (auto v : vec) cnt += ar[v] > 0;

        cout << cnt << "\n";
    }

    return 0;
}
