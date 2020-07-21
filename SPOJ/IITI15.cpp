#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct query {
    int L,R,ind;
};
const int N=20020;
int n,m,block,a[N],temp[N],currL,currR;
ll inv,res[N],BIT[N];
query q[N];

bool comp(query q1,query q2){
    int ql1=q1.L/block,ql2=q2.L/block;
    if (ql1!=ql2)
        return ql1<ql2;
    return q1.R<q2.R;
}

void update(int i,int v){
    for(;i<=n;i+=i&-i)
        BIT[i]+=v;
}

ll query(int i){
    ll sum=0;
    for(;i>0;i-=i&-i)
        sum+=BIT[i];
    return sum;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]),temp[i]=a[i];
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        scanf("%d%d",&q[i].L,&q[i].R);
        q[i].ind=i;
        q[i].L--,q[i].R--;
    }
    block = (int)ceil(sqrt(n));
    sort(temp,temp+n);
    for (int i=0;i<n;i++)
        a[i]=lower_bound(temp,temp+n,a[i])-temp+1;
    sort(q,q+m,comp);
    for (int i=0;i<m;i++) {
        while(currL<q[i].L)
            inv-=query(a[currL]-1),update(a[currL++],-1);
        while(currL>q[i].L)
            --currL,inv+=query(a[currL]-1),update(a[currL],1);
        while(currR<=q[i].R)
            inv+=query(n)-query(a[currR]),update(a[currR],1),currR++;
        while(currR>q[i].R+1)
            currR--,inv-=query(n)-query(a[currR]),update(a[currR],-1);
        res[q[i].ind]=inv;
    }
    for (int i=0;i<m;i++)
        printf("%I64d\n",res[i]);
}
