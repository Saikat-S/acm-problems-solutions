#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int isVowel(char ch) {
    if(ch == 'a' ||ch == 'u' ||ch == 'e' ||ch == 'i' ||ch == 'o') {
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    string a,b;
    int tc;
    cin>>tc;
    for(int i = 1; i<=tc; i++) {
        cin>>a>>b;
        bool flag = false;
        int al = a.size();
        int bl = b.size();
        if(al == bl) {
            for(int i = 0; i<al; i++) {
				
                if((!isVowel(a[i]) && !isVowel(b[i]) && a[i]!=b[i]) || (!isVowel(a[i]) && isVowel(b[i]))|| (isVowel(a[i]) && !isVowel(b[i]))) {
                    printf("No\n");
                    flag = true;
                    break;
                }
            }
            if(!flag) printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
