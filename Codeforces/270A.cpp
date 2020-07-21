#include <bits/stdc++.h>
using namespace std;
int n,a;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        if ( 360%(180-a) ) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
