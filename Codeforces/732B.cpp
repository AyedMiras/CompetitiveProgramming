#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[505],b[505];

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];

    if (n==1) {
        cout << 0 << endl;
        cout << a[0] << endl;
        return 0;
    }

    b[0]= a[0];

    for (int i=1;i<n;i++) {
        if (k- b[i-1] > a[i]) cnt+= k - b[i-1] - a[i];
        b[i] = max(a[i],k - b[i-1]);
    }
    cout << cnt << endl;
    for (int i=0;i<n;i++) {
        cout << b[i] << " "[i==n-1];
    }
}
