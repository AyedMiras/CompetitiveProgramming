#include <bits/stdc++.h>
using namespace std;
const int N=100100;
long long int n,m,w,h,a[N],st[4*N],lazy[4*N];

void build(int si, int ss, int se) {
    if (ss==se) {
        st[si]=a[ss];
        return;
    }
    int mid = ss+(se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si] = max(st[2*si+1],st[2*si+2]);
}

void print(int si, int ss, int se) {
    cout << ss << " " << se << " " << st[si] << endl;
    if (ss!=se) {
        int mid=ss+(se-ss)/2;
        print(2*si+1,ss,mid);
        print(2*si+2,mid+1,se);
    }
}

long long int query(int si, int ss, int se, int qs, int qe) {
    if (lazy[si]) {
        st[si]=lazy[si];
        if (se!=ss)
            lazy[2*si+1]=lazy[2*si+2]=lazy[si];
        lazy[si]=0;
    }
    if (ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return st[si];
    int mid = ss+(se-ss)/2;
    return max(query(2*si+1,ss,mid,qs,qe),query(2*si+2,mid+1,se,qs,qe));
}

void update(int si, int ss, int se, int qs, int qe, long long int u) {
    if (lazy[si]) {
        st[si]=lazy[si];
        if (se!=ss)
            lazy[2*si+1]=lazy[2*si+2]=lazy[si];
        lazy[si]=0;
    }
    if (ss>qe || se<qs)
        return;
    if (ss>=qs && se<=qe) {
        st[si] = u;
        if (ss!=se) {
            lazy[2*si+1]=lazy[2*si+2]=u;
        }
        return;
    }
    int mid = ss+(se-ss)/2;
    update(2*si+1,ss,mid,qs,qe,u);
    update(2*si+2,mid+1,se,qs,qe,u);
    st[si]=max(st[2*si+1],st[2*si+2]);
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    build(0,0,n-1);
    //print(0,0,n-1);
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> w >> h;
        long long int q = query(0,0,n-1,0,w-1);
        cout << q << endl;
        update(0,0,n-1,0,w-1,q+h);
    }
}
