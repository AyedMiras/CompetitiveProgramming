#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,q,x[N],m[N];
int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> x[i];
    cin >> q;
    for (int i=0;i<q;i++)
        cin >> m[i];
    sort(x,x+n);
    for (int i=0;i<q;i++) {
        cout << upper_bound(x,x+n,m[i]) - x << endl;
    }
}
