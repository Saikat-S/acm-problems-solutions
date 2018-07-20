#include<iostream>
#include<vector>
#include<cstdio>
#include<iomanip>
#define MAX 10000
using namespace std;
int main()
{
    double ar[MAX],sum,multi;
    int rem;
    int n;
    scanf("%d", &n);
    for(int t = 1; t<=n; t++) {
        sum = 0;
        for(int i = 0; i<12; i++) {
            scanf("%lf", &ar[i]);
            sum+=ar[i];
        }
        double avg = sum/12.0;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        if(avg>=1000) {
            rem = avg/1000;
            multi = avg - rem*1000;
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            if(multi<10.0) {
                cout<<t<<" "<<"$"<<rem<<","<<"00"<<multi<<endl;
            }
            else if(multi<100.0) {
                cout<<t<<" "<<"$"<<rem<<","<<"0"<<multi<<endl;
            }
            else {
                cout<<t<<" "<<"$"<<rem<<","<<multi<<endl;
            }

        }
        else {
            cout<<t<<" "<<"$"<<avg<<endl;
        }
    }
    return 0;
}
