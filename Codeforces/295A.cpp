#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100100;
int n,m,k;
ll a[N],l[N],r[N],x[N],y[N],d[N],op[N],diff[N],cum[N];

int main() {
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) cin >> a[i],diff[i] = (i?a[i]-a[i-1]:a[0]);
    for (int i=0;i<m;i++) cin >> l[i] >> r[i] >> d[i];
    for (int i=0;i<k;i++) cin >> x[i] >> y[i],op[x[i]-1]++, op[y[i]]--;
    for (int i=0;i<m;i++) cum[i] = (i?op[i] + cum[i-1]:op[0]),diff[l[i]-1]+= d[i]*cum[i], diff[r[i]]-=d[i]*cum[i];
    ll d=diff[0];
    cout << d;
    for (int i=1;i<n;i++)
        cout << " " << (d+=diff[i]);
    cout << endl;
}
