#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
ll T,n,q,BIT1[N],BIT2[N];

void update1(int i,ll v){
    for(;i<=n;i+=i&-i)
        BIT1[i]+=v;
}

void update2(int i,ll v){
    for(;i<=n;i+=i&-i)
        BIT2[i]+=v;
}

ll query1(int i){
    ll sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT1[i];
    return sum;
}

ll query2(int i){
    ll sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT2[i];
    return sum;
}


int main() {
    cin >> T;
    while(T--){
        memset(BIT1,0,sizeof(BIT1));
        memset(BIT2,0,sizeof(BIT2));
        cin >> n >> q;
        for (int i=0;i<q;i++){
            ll flag,l,r,v;
            cin >> flag >> l >> r;
            if (!flag){
                cin >>  v;
                update1(l,v);
                update1(r+1,-v);
                update2(l,v*(l-1));
                update2(r+1,-v*r);
            }
            else {
                cout << query1(r)*r-query2(r)-query1(l-1)*(l-1)+query2(l-1) << endl;
            }
        }
    }
}
