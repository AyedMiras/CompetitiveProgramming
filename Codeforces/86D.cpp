#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct query {int L,R,ind;};
const int N=200200;
const int M=1000100;
ll n,p,block,t,a[N],cnt[M],res[N];
query q[N];


bool comp(query q1,query q2) {
    if (q1.L/block!=q2.L/block)
        return q1.L/block < q2.L/block;
    return q1.R < q2.R;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> t;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<t;i++)
        cin >> q[i].L >> q[i].R,q[i].ind=i,q[i].L--,q[i].R--;
    block = ceil(sqrt(n));
    sort(q,q+t,comp);
    int ql=0,qr=0;
    for (int i=0;i<t;i++) {
        while(ql<q[i].L){
            p-=(2*(--cnt[a[ql]])+1)*a[ql];
            ql++;
        }
        while(ql>q[i].L){
            p+=(2*(cnt[a[--ql]]++)+1)*a[ql];
        }
        while(qr<=q[i].R){
            p+=(2*(cnt[a[qr]]++)+1)*a[qr];
            qr++;
        }
        while(qr>q[i].R+1){
            p-=(2*(--cnt[a[--qr]])+1)*a[qr];
        }
        res[q[i].ind]=p;
    }
    for (int i=0;i<t;i++)
        cout << res[i] << endl;
}
