#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2000200;
int n4,a[N];
ll s;

int main() {
    ios::sync_with_stdio(0);
    cin >> n4;
    for (int i=0;i<n4;i++) cin >> a[i];
    sort(a,a+n4);
    for (int i=1;i<=n4;i*=4)
        for (int j=n4-1;j>=n4-i;j--)
            s+=a[j];

    cout << s << endl;
}
