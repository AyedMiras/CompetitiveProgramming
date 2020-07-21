#include <bits/stdc++.h>
using namespace std;
int p,q,l,r,a[55],b[55],c[55],d[55],cnt;

int main() {
    cin >> p >> q >> l >> r;
    for (int i=0;i<p;i++) cin >> a[i] >> b[i];
    for (int i=0;i<q;i++) cin >> c[i] >> d[i];
    for (int i=l;i<=r;i++) {
        for (int j=0;j<q;j++) {
            for (int k=0;k<p;k++) {
                if (min(b[k],d[j]+i)>=max(a[k],c[j]+i)) cnt++, k=p,j=q;
            }
        }
    }
    cout << cnt << endl;
}
