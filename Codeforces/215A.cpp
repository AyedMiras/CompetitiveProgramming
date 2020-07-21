#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n,m,a[N],b[N],mx,cnt;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    for (int i=0;i<m;i++) cin >> b[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (!(b[j]%a[i]))
                mx = max(mx,b[j]/a[i]);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (!(b[j]%a[i]) && b[j]/a[i] == mx)
                cnt++;
    cout << cnt << endl;
}
