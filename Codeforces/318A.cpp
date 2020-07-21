#include <bits/stdc++.h>
using namespace std;
long long int n,k;

int main() {
    cin >> n >> k;
    if (k<=(n/2)+(n&1)) cout << 2*(k-1)+1 << endl;
    else cout << 2*(k- n/2 - (n&1) );
}
