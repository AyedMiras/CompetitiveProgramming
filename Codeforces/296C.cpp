#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
int n,m,k;
ll a[N],l[N],r[N],d[N],x[N],y[N],BIT[2][N];

void update(int flag,int i,ll v){
    for(;i<=(flag?n:m);i+=i&-i)
        BIT[flag][i]+=v;
}

ll query(int flag,int i){
    ll sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT[flag][i];
    return sum;
}

int main() {
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=m;i++)
        cin >> l[i] >> r[i] >> d[i];
    for (int i=1;i<=k;i++){
        cin >> x[i] >> y[i];
        update(0,x[i],1);
        update(0,y[i]+1,-1);
    }
    for (int i=1;i<=m;i++){
        update(1,l[i],d[i]*query(0,i));
        update(1,r[i]+1,-d[i]*query(0,i));
    }
    for (int i=1;i<=n;i++)
        cout << a[i]+query(1,i) << " \n"[i==n];
}
