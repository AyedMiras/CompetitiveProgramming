#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1001000;
int n,q;
ll a[N],BIT[N];

ll getSum(int i){
    ll sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT[i];
    return sum;
}

void update(int i,int x) {
    for(;i<=n;i+=i&-i)
        BIT[i]+=x;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i],update(i,a[i]);
    cin >> q;
    for (int i=0;i<q;i++){
        char c;
        int u,v;
        cin >> c >> u >> v;
        if (c=='q')
            cout << getSum(v)-getSum(u-1) << endl;
        else
            update(u,v);
    }
}
