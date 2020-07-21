#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll l,r;

int main() {
    cin >> l >> r;
    if (l&1) l++;
    if (r-l <2) cout << -1 << endl;
    else cout << l << " " << l+1 << " " << l+2 << endl;
}
