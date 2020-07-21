#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int M = 1000100;
int T,n,a[N],q,x,y,v,sieve[M],lazy[4*N],st[4*N];
bool flag;

void eras() {
    sieve[0]=sieve[1]=1;
    for (int i=2;i<M;i++)
        if (!sieve[i])
            for (int j=2;i*j<M;j++)
                sieve[i*j]=1;
}

void build(int si, int ss, int se) {
    if (ss==se) {
        st[si] = 1-sieve[a[ss]];
        return;
    }
    int mid = ss + (se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si] = st[2*si+1]+st[2*si+2];
}

void update(int si, int ss, int se, int us, int ue, int val) {
    if (lazy[si]!=-1) {
        st[si]=(se-ss+1)*lazy[si];
        if(se!=ss)
            lazy[2*si+1]=lazy[si], lazy[2*si+2]=lazy[si];
        lazy[si]=-1;
    }
    if (ss > ue || se < us) return;
    if (ss>= us && se <=ue) {
        st[si]= (se-ss+1)*val;
        if (se!=ss)
            lazy[2*si+1]=val, lazy[2*si+2]=val;
        return;
    }
    int mid = ss + (se-ss)/2;
    update(2*si+1,ss,mid,us,ue,val);
    update(2*si+2,mid+1,se,us,ue,val);
    st[si] = st[2*si+1]+st[2*si+2];

}

int query(int si, int ss, int se, int qs, int qe) {
    if (lazy[si]!=-1) {
        st[si]=(se-ss+1)*lazy[si];
        if(se!=ss)
            lazy[2*si+1]=lazy[si], lazy[2*si+2]=lazy[si];
        lazy[si]=-1;
    }
    if (ss>qe || se <qs) return 0;
    if (ss>=qs && se<=qe) {
        return st[si];
    }
    int mid = ss+ (se-ss)/2;
    return query(2*si+1,ss,mid,qs,qe) + query(2*si+2,mid+1,se,qs,qe);
}

void init() {
    memset(lazy,-1,sizeof(lazy));
    build(0,0,n-1);
}

void print(int si, int ss, int se ){
    cout << st[si] << " " << ss << " " << se << endl;
    if (ss == se) return;
    int mid = ss +(se-ss)/2;
    print(2*si+1,ss,mid);
    print(2*si+2,mid+1,se);
}

int main() {
    eras();
    scanf("%d",&T);
    for (int t=0;t<T;t++) {
        printf("Case %d:\n",t+1);
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;i++) scanf("%d",a+i);
        init();
        //print(0,0,n-1);
        for (int i=0;i<q;i++) {
            scanf("%d %d %d",&flag,&x,&y);
            if (flag) printf("%d\n",query(0,0,n-1,--x,--y));
            else  {
                scanf("%d",&v);
                update(0,0,n-1,--x,--y,1-sieve[v]);
                //print(0,0,n-1);
            }
        }
    }
}
