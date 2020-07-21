#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;
const int N=2020;
const int L=12;
ll n,l,dist[N][N],depth[N],parent[N][L],path[N][L],flag;
set<tuple<ll,int,int>> s;
vector<pair<int,ll>> tree[N];

void dfs(int u, int p, ll backEdge) {
    parent[u][0]=p;
    if(p!=-1) {
        depth[u]=depth[p]+1;
        path[u][0]=backEdge;
    }
    for(int i=1;i<l;i++) {
        if(parent[u][i-1]==-1)
            break;
        parent[u][i]=parent[parent[u][i-1]][i-1];
        path[u][i]=path[u][i-1]+path[parent[u][i-1]][i-1];
    }
    for(int i=0;i<tree[u].size();i++)
        if(tree[u][i].first!=p)
            dfs(tree[u][i].first,u,tree[u][i].second);
}

ll shPath(int u, int v) {
    ll res=0;
    if (depth[u]<depth[v])
        swap(u,v);
    for(int i=l-1;i>=0;i--) {
        if(parent[u][i]!=-1 && depth[parent[u][i]]>=depth[v])
            res+=path[u][i],u=parent[u][i];
    }
    if (u==v)
        return res;
    for(int i=l-1;i>=0;i--) {
        if(parent[u][i]!=parent[v][i]) {
            res+=path[u][i]+path[v][i];
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    return res+path[u][0]+path[v][0];
}

void init() {
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            s.insert(make_tuple(dist[i][j],i,j));
    for(int k=0;k<n-1;k++) {
        ll d=get<0>(*(s.begin()));
        int i=get<1>(*(s.begin()));
        int j=get<2>(*(s.begin()));
        s.erase(s.begin());
        tree[i].pb(mp(j,d));
        tree[j].pb(mp(i,d));
    }
    l=(int)ceil(log2(n))+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<l;j++)
            parent[i][j]=-1;
    dfs(0,-1,0);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> dist[i][j];
    if(n==1)
        return cout << "YES" << endl,0;
    for(int i=0;i<n;i++) {
        if(dist[i][i])
            flag=1;
        for(int j=i+1;j<n;j++)
            if(!dist[i][j] || dist[i][j]!=dist[j][i])
                flag=1;
    }
    if(flag)
        return cout << "NO" << endl,0;
    init();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if (shPath(i,j)!=dist[i][j])
                flag=1;
    cout << (flag?"NO":"YES") << endl;
}
