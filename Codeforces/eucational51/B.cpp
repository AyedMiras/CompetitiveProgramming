#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll l,r;

int main() {
    cin >> l >> r;
    cout << "YES" << endl;
    for (ll i=0;i<r-l+1;i+=2)
        cout << l+i << " " << l+i+1 << endl;
}

