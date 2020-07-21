#include <bits/stdc++.h>
using namespace std;
const int N = 200020;
int n,m,a[N],b[N];

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    sort(a,a+n);
    for (int i=0;i<m;i++) {
        cout << upper_bound(a,a+n,b[i]) - a << " \n"[i==m-1];
    }
}
