#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,a,b,x;

int main() {
    cin >> n >> a >> b;
    for (int i=0;i<n;i++) {
        cin >> x;
        ll d = (x*a)/b;
        cout << x - (d*b)/a - ((d*b)%a!=0) << " \n"[i==n-1];
    }
}

