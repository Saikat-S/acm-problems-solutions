#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;
bool cmp(string a, string b){
	if(a.size() == b.size()) return a > b;
	else return a.size() > b.size();
}
int main () {
    int n;
    string str;
    vector<string>V, ans;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        V.push_back (s);
    }

    sort (V.begin(), V.end() , cmp);

    //~ for (int i = 0; i < n; i++) {
        //~ cout << V[i] << " ";
    //~ }

    //~ cout << "\n";
    int flag = 0;

    for (int i = 1; i < n; i++) {
        string pp = V[i - 1];
        string cc = V[i];
        std::size_t found = pp.find (cc);

        if (found != std::string::npos) {
        } else {
            //~ cout << pp << " " << cc;
            flag  =  1;
            break;
        }
    }

    if (flag == 0) {
        cout << "YES\n";

        for (int i = n-1; i >= 0; i--) {
            cout << V[i] << "\n";
        }

        cout << "\n";

    } else cout << "NO\n";

    return 0;
}

