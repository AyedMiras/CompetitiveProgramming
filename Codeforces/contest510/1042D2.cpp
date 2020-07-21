#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=200200;
ll n,t,cnt,a[N],cum[N];

void _merge(int l,int r,int mid) {
    ll aux[N];
    for (int k=0;k<mid-l+1;k++){
        int lb = lower_bound(cum+mid+1,cum+r+1,cum[k+l]+t)-cum-mid-1;
        cnt+=lb;
    }
    int i=0,j=0;
    while(i<mid-l+1 && j<r-mid)
        aux[i+j]=(cum[l+i]<cum[mid+1+j]?cum[l+i++]:cum[mid+1+j++]);
    while(i<mid-l+1)
        aux[i+j]=cum[l+i++];
    while(j<r-mid)
        aux[i+j]=cum[mid+1+j++];
    for (int k=l;k<=r;k++)
        cum[k]=aux[k-l];
}

void _sort(int l,int r) {
    if (l>=r)
        return;
    int mid=l+(r-l)/2;
    _sort(l,mid);
    _sort(mid+1,r);
    _merge(l,r,mid);
}

int main() {
    cin >> n >> t;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
        cum[i]=cum[i-1]+a[i-1];
    _sort(0,n);
    cout << cnt << endl;
}
