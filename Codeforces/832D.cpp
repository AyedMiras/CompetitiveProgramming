#include <bits/stdc++.h>
using namespace std;
const int N=100100;
const int L=25;
int n,q,a,b,c,depth[N],parent[N][L];
vector<int> tree[N];

void dfs(int u,int p) {
    parent[u][0]=p;
    if(p!=-1)
        depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        if(parent[u][i-1]!=-1)
            parent[u][i]=parent[parent[u][i-1]][i-1];
    for(int i=0;i<tree[u].size();i++)
        if(tree[u][i]!=p)
            dfs(tree[u][i],u);
}

int lca(int u,int v,int flag) {
    int res=1;
    if(depth[u]<depth[v])
        swap(u,v);
    for(int i=L-1;i>=0;i--) {
        if(parent[u][i]!=-1 && depth[parent[u][i]]>=depth[v]) {
            res+=(1<<i);
            u=parent[u][i];
        }
    }
    if(u==v)
        return(flag?res:u);
    res++;
    for(int i=L-1;i>=0;i--) {
        if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i]) {
            u=parent[u][i];
            v=parent[v][i];
            res+=(1<<(i+1));
        }
    }
    return (flag?res+1:parent[u][0]);
}

int solve(int s,int t,int f) {
    int u=lca(s,f,0);
    int v=lca(t,f,0);
    if (depth[u]<depth[v]) {
        return lca(v,f,1);
    }
    else if(depth[v]<depth[u]) {
        return lca(u,f,1);
    }
    else
        return lca(lca(s,t,0),f,1);
}

void init() {
    for(int i=0;i<n;i++)
        for(int j=0;j<L;j++)
            parent[i][j]=-1;
    dfs(0,-1);
}

int main() {
    cin >> n >> q;
    for(int i=1;i<n;i++) {
        cin >> a;
        a--;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    init();
    for(int i=0;i<q;i++) {
        cin >> a >> b >> c;
        a--,b--,c--;
        int res=solve(a,b,c);
        res=max(res,solve(b,a,c));
        res=max(res,solve(a,c,b));
        res=max(res,solve(c,a,b));
        res=max(res,solve(b,c,a));
        res=max(res,solve(c,b,a));
        cout << res << endl;
    }
}
