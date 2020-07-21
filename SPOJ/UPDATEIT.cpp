#include <bits/stdc++.h>
using namespace std;
const int N=10100;
int n,T,u,q,a[N],BIT[N];

int query(int i){
    i++;
    int sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT[i];
    return sum;
}

void update(int l,int r,int val){
    l++;r++;
    for(;l<=n;l+=l&-l)
        BIT[l]+=val;
    for(r++;r<=n;r+=r&-r)
        BIT[r]-=val;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        memset(BIT,0,sizeof(BIT));
        cin >> n >> u;
        for (int i=0;i<u;i++){
            int l,r,val;
            cin >> l >> r >> val;
            update(l,r,val);
        }
        cin >> q;
        for (int i=0;i<q;i++){
            int ind;
            cin >> ind;
            cout << query(ind) << endl;
        }
    }
}
