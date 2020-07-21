#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
const int M=330;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,a[N],l[M],r[M],st[4*N],lazy[4*N];
vector<int> bPtr[N],lPtr[N],rPtr[N];

ll build(int si, int ss, int se) {
    if(ss==se)
        return st[si]=a[ss];
    int mid=ss+(se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si]=max(st[2*si+1],st[2*si+2]);
}

void update(int si, int ss, int se, int qs, int qe, int val) {
    if(lazy[si]) {
        st[si]+=lazy[si];
        if(ss!=se) {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(ss>qe || se<qs)
        return;
    if(ss>=qs && se<=qe) {
        st[si]+=val;
        if(ss!=se) {
            lazy[2*si+1]+=val;
            lazy[2*si+2]+=val;
        }
        return;
    }
    int mid=ss+(se-ss)/2;
    update(2*si+1,ss,mid,qs,qe,val);
    update(2*si+2,mid+1,se,qs,qe,val);
    st[si]=max(st[2*si+1],st[2*si+2]);
}

ll query(int si, int ss, int se, int qs, int qe) {
    if(lazy[si]) {
        st[si]+=lazy[si];
        if(ss!=se) {
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(ss>qe || se<qs)
        return -INF;
    if(ss>=qs && se<=qe) {
        return st[si];
    }
    int mid=ss+(se-ss)/2;
    return max(query(2*si+1,ss,mid,qs,qe),query(2*si+2,mid+1,se,qs,qe));
}

void print(int si, int ss, int se) {
    cout << ss << " " << se << " " << st[si] << endl;
    if(ss!=se) {
        int mid=ss+(se-ss)/2;
        print(2*si+1,ss,mid);
        print(2*si+2,mid+1,se);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    build(0,0,n-1);
    for(int i=0;i<m;i++) {
        cin >> l[i] >> r[i];
        l[i]--,r[i]--;
    }
    for(int i=0;i<m;i++) {
        for(int j=l[i];j<=r[i];j++)
            bPtr[j].push_back(i);
        lPtr[l[i]].push_back(i);
        rPtr[r[i]+1].push_back(i);
    }
    ll diff=-INF,ind;
    for(int i=0;i<n;i++) {
        for(int j=0;j<lPtr[i].size();j++)
            update(0,0,n-1,l[lPtr[i][j]],r[lPtr[i][j]],-1);
        for(int j=0;j<rPtr[i].size();j++)
            update(0,0,n-1,l[rPtr[i][j]],r[rPtr[i][j]],1);
        if(query(0,0,n-1,0,n-1)-query(0,0,n-1,i,i)>diff) {
            diff=query(0,0,n-1,0,n-1)-query(0,0,n-1,i,i);
            ind=i;
        }
    }
    cout << diff << endl;
    cout << bPtr[ind].size() << endl;
    for(int i=0;i<bPtr[ind].size();i++)
        cout << bPtr[ind][i]+1 << " \n"[i==bPtr[ind].size()-1];
}
