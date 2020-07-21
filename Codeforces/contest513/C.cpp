#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2020;
ll n,m,x,cnt,m4x,a[N],b[N],cumA[N],cumB[N],st[4*N*N];
pair<ll,ll> interv[N*N];

void build(int si,int ss,int se){
    if (ss==se){
        st[si]=interv[ss].second;
        return;
    }
    int mid=ss+(se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si]=max(st[2*si+1],st[2*si+2]);
}

ll query(int si,int ss,int se,int qs,int qe){
    if (ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return st[si];
    int mid=ss+(se-ss)/2;
    return max(query(2*si+1,ss,mid,qs,qe),query(2*si+2,mid+1,se,qs,qe));
}

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i],cumA[i]=a[i]+cumA[i-1];
    for (int i=1;i<=m;i++)
        cin >> b[i],cumB[i]=b[i]+cumB[i-1];
    cin >> x;
    for (int i=0;i<=m-1;i++)
        for (int j=i+1;j<=m;j++)
            interv[cnt].first=cumB[j]-cumB[i],interv[cnt++].second=j-i;
    sort(interv,interv+cnt);
    build(0,0,cnt-1);
    for (int i=0;i<=n-1;i++) {
        for (int j=i+1;j<=n;j++) {
            int l=upper_bound(interv,interv+cnt,make_pair(x/(cumA[j]-cumA[i]),cnt)) - interv;
            if (l)
                m4x = max(m4x,query(0,0,cnt-1,0,l-1)*(j-i));
        }
    }
    cout << m4x << endl;
}
