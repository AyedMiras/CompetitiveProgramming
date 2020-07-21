#include <bits/stdc++.h>
using namespace std;
long long int n;

int main() {
    cin >> n;
    if (!n) cout << 0 << endl;
    else if (++n&1) cout << n << endl;
    else cout << n/2 << endl;
}
