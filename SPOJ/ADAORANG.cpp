#include <bits/stdc++.h>
using namespace std;
const int N=500500;
const int M=255;
const int L=25;
int T,n,l,q,r,a,b,shades[N],parent[N][L],depth[N];
bitset<M> shadeMask[N];
vector<int> tree[N];

void dfs(int u, int p) {
    parent[u][0]=p;
    if(p!=-1)
        depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        if(parent[u][i-1]!=-1)
            parent[u][i]=parent[parent[u][i-1]][i-1];
    for(int i=0;i<tree[u].size();i++) {
        if(tree[u][i]!=p) {
            dfs(tree[u][i],u);
            shadeMask[u]|=shadeMask[tree[u][i]];
        }
    }
}

int solve(int u, int v) {
    if(depth[u]<depth[v])
        swap(u,v);
    for(int i=L-1;i>=0;i--)
        if(parent[u][i]!=-1 && depth[parent[u][i]]>=depth[v])
            u=parent[u][i];
    if(u==v)
        return u;
    for(int i=L-1;i>=0;i--) {
        if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i]) {
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    return parent[u][0];
}

void init() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<L;j++)
            parent[i][j]=-1;
        tree[i].clear();
        shades[i]=0;
        depth[i]=0;
        shadeMask[i].reset();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--) {
        cin >> n >> q >> r;
        init();
        for(int i=0;i<n;i++) {
            cin >> shades[i];
            shades[i]--;
            shadeMask[i][shades[i]]=1;
        }
        for(int i=0;i<n-1;i++) {
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        dfs(r,-1);
        for(int i=0;i<q;i++) {
            cin >> a >> b;
            cout << (int)shadeMask[solve(a,b)].count() << endl;
        }
    }
}
