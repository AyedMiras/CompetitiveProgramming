#include <bits/stdc++.h>
using namespace std;
long long int n,m,km,kM;

long long int sum(long long int a) {
    return (a*(a-1))/2;
}
int main() {
    cin >> n >> m;
    if (m==1) km = kM = sum(n);
    else {
        kM =  sum(n-m+1);
        km =  sum(n/m+1)*(n%m) + sum(n/m)*(m -n%m);
    }
    //cout << (5000000/12)*11 << " " << 5000000 - (5000000/12)*11;
    cout << km << " " << kM << endl;
}
