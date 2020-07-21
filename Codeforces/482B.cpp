#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,m,l[N],r[N],q[N],lazy[4*N],st[4*N];

int query(int si,int ss,int se,int qs,int qe){
    if (lazy[si]){
        st[si]^=lazy[si];
        if (ss!=se){
            lazy[2*si+1]^=lazy[si];
            lazy[2*si+2]^=lazy[si];
        }
        lazy[si]=0;
    }
    if (ss>qe || se<qs)
        return (1<<30)-1;
    if (ss>=qs && se<=qe)
        return st[si];
    int mid=ss+(se-ss)/2;
    return query(2*si+1,ss,mid,qs,qe)&query(2*si+2,mid+1,se,qs,qe);
}

void print(int si,int ss,int se){
    if (lazy[si]){
        st[si]^=lazy[si];
        if (ss!=se){
            lazy[2*si+1]^=lazy[si];
            lazy[2*si+2]^=lazy[si];
        }
        lazy[si]=0;
    }
    cout << st[si] << " " << ss << " " << se << endl;
    if(ss!=se){
        int mid=ss+(se-ss)/2;
        print(2*si+1,ss,mid);
        print(2*si+2,mid+1,se);
    }
}

void update(int si,int ss,int se,int qs,int qe,int mask){
    if (lazy[si]){
        st[si]^=lazy[si];
        if (ss!=se){
            lazy[2*si+1]^=lazy[si];
            lazy[2*si+2]^=lazy[si];
        }
        lazy[si]=0;
    }
    if (ss>qe || se<qs)
        return;
    if (ss>=qs && se<=qe) {
        st[si]^=mask;
        if (ss!=se){
            lazy[2*si+1]^=mask;
            lazy[2*si+2]^=mask;
        }
        return;
    }
    int mid=ss+(se-ss)/2;
    update(2*si+1,ss,mid,qs,qe,mask);
    update(2*si+2,mid+1,se,qs,qe,mask);
    st[si]=st[2*si+1]&st[2*si+2];
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        cin >> l[i] >> r[i] >> q[i];
        update(0,0,n-1,--l[i],--r[i],q[i]);
    }
    for (int i=0;i<m;i++)
        if (query(0,0,n-1,l[i],r[i])!=q[i])
            return 0*printf("NO\n");
    //print(0,0,n-1);
    cout << "YES" << endl;
    for (int i=0;i<n;i++)
        cout << query(0,0,n-1,i,i) << " \n"[i==n-1];
}
