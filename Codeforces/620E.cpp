#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=450450;
const int M=61;
int n,m,c[N],lazy[8*N],in[2*N],out[2*N];
vector<int> tree[N],flat;
ll st[8*N];

void push(int si,int ss,int se) {
    if(lazy[si]==-1)
        return;
    st[si]=(1LL<<lazy[si]);
    if(ss!=se)
        lazy[2*si+1]=lazy[2*si+2]=lazy[si];
    lazy[si]=-1;
}

void build(int si,int ss,int se) {
    if(ss==se) {
        st[si]=(1LL<<c[flat[ss]]);
        return;
    }
    int mid=ss+(se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si]=st[2*si+1]|st[2*si+2];
}

void update(int si,int ss,int se,int qs,int qe,int val) {
    push(si,ss,se);
    if(ss>qe || se<qs)
        return;
    if(ss>=qs && se<=qe) {
        st[si]=(1LL<<val);
        if(ss!=se) {
            lazy[2*si+1]=val;
            lazy[2*si+2]=val;
        }
        return;
    }
    int mid=ss+(se-ss)/2;
    update(2*si+1,ss,mid,qs,qe,val);
    update(2*si+2,mid+1,se,qs,qe,val);
    st[si]=st[2*si+1]|st[2*si+2];
}

ll query(int si,int ss,int se,int qs,int qe) {
    push(si,ss,se);
    if(ss>qe || se<qs)
        return 0;
    if(ss>=qs && se<=qe)
        return st[si];
    int mid=ss+(se-ss)/2;
    return query(2*si+1,ss,mid,qs,qe)|query(2*si+2,mid+1,se,qs,qe);
}

void dfs(int u, int p) {
    flat.push_back(u);
    in[u]=flat.size()-1;
    for(int i=0;i<tree[u].size();i++)
        if(tree[u][i]!=p)
            dfs(tree[u][i],u);
    flat.push_back(u);
    out[u]=flat.size()-1;
}

int cnt(ll x) {
    int res=0;
    for(ll i=0;i<=M;i++)
        if((1LL<<i)&x)
            res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> c[i];
        c[i]--;
    }
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin >> x >> y;
        x--,y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    memset(lazy,-1,sizeof(lazy));
    dfs(0,-1);
    build(0,0,2*n-1);
    for(int i=0;i<m;i++) {
        int t,v,col;
        cin >> t;
        if(t==1) {
            cin >> v >> col;
            v--,col--;
            update(0,0,2*n-1,in[v],out[v],col);
        }
        else {
            cin >> v;
            v--;
            cout << cnt(query(0,0,2*n-1,in[v],out[v])) << endl;
        }
    }
}
