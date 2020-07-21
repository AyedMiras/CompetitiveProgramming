#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,m,q,a[N],cum[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i],cum[i]=a[i]+(i?cum[i-1]:0);
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> q;
        cout << lower_bound(cum,cum+n,q) - cum + 1 << endl;
    }
}
