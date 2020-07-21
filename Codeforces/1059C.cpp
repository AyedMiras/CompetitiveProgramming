#include <bits/stdc++.h>
using namespace std;
int n,gcd=1;

int main() {
    cin >> n;
    while(n>3){
        for (int i=0;i<(n+1)/2;i++)
            cout << gcd << " ";
        n/=2;
        gcd*=2;
    }
    if (n==1)
        cout << gcd;
    if (n==2)
        cout << gcd << " " << 2*gcd;
    if (n==3)
        cout << gcd << " " << gcd << " " << 3*gcd;
    cout << endl;
}
