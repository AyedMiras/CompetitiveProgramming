#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=200200;
int n,q,l,r;
ll diff[N],cum[N],a[N],s;


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<q;i++) {
        cin >> l >> r ;
        diff[--l]++;
        diff[r]--;
    }
    for (int i=0;i<n;i++) {
        cum[i] = diff[i]+ (i?cum[i-1]:0);
    }
    sort(cum,cum+n);
    sort(a,a+n);
    for (int i=0;i<n;i++)
        s+= cum[i]*a[i];
    cout << s << endl;
}
