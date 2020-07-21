#include <bits/stdc++.h>
using namespace std;
int n,a[1010];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    if (a[0] == 1) cout << -1 << endl;
    else cout << 1 << endl;
}
