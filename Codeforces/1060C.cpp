#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2020;
ll n,m,a[N],b[N],x,ind,cumA[N],cumB[N],cumMax[N*N],res;
pair<ll,ll> cumR[N*N];

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        cumA[i]=cumA[i-1]+a[i];
    }
    for (int i=1;i<=m;i++){
        cin >> b[i];
        cumB[i]=cumB[i-1]+b[i];
    }
    cin >> x;
    for (int i=0;i<m;i++){
        for (int j=i+1;j<=m;j++){
            cumR[ind].first=cumB[j]-cumB[i];
            cumR[ind++].second=j-i;
        }
    }
    sort(cumR,cumR+ind);
    cumMax[0]=cumR[0].second;
    for (int i=1;i<ind;i++)
        cumMax[i] = max(cumMax[i-1],cumR[i].second);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<=n;j++){
            int u = upper_bound(cumR,cumR+ind,make_pair(x/(cumA[j]-cumA[i]),ind)) - cumR;
            if (u)
                res=max(res,cumMax[u-1]*(j-i));
        }
    }
    cout << res << endl;
}
