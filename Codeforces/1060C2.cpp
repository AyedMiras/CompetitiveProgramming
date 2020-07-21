#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2020;
ll n,m,x,a[N],b[N],cumA[N],cumB[N],rangeA[N],rangeB[N];
int res;

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        cumA[i]=a[i]+cumA[i-1];
    }
    for (int i=1;i<=m;i++) {
        cin >> b[i];
        cumB[i]=b[i]+cumB[i-1];
    }
    cin >> x;
    memset(rangeA,0x3f,sizeof(rangeA));
    memset(rangeB,0x3f,sizeof(rangeB));
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            rangeA[j-i]=min(rangeA[j-i],cumA[j]-cumA[i]);
        }
    }
    for (int i=0;i<m;i++)
        for (int j=i+1;j<=m;j++)
            rangeB[j-i]=min(rangeB[j-i],cumB[j]-cumB[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (rangeA[i]*rangeB[j]<=x)
                res=max(res,i*j);
    cout << res << endl;
}

