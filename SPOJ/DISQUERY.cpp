#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
const int N=100100;
const int L=(int)ceil(log(N)/log(2))+1;
const int INF=0x3f3f3f3f;
int n,k,l,a,b,c,d,e,ansMin,ansMax,depth[N],parent[N][L],minR[N][L],maxR[N][L];
vector<pair<int,int>> tree[N];

void dfs(int u, int p, int backEdge) {
    parent[u][0]=p;
    if (p!=-1) {
        maxR[u][0]=minR[u][0]=backEdge;
        depth[u]=depth[p]+1;
    }
    for(int i=1;i<l;i++) {
        if (parent[u][i-1]==-1)
            break;
        parent[u][i]=parent[parent[u][i-1]][i-1];
        maxR[u][i]=max(maxR[parent[u][i-1]][i-1],maxR[u][i-1]);
        minR[u][i]=min(minR[parent[u][i-1]][i-1],minR[u][i-1]);
    }
    for(int i=0;i<tree[u].size();i++)
        if(tree[u][i].first!=p)
            dfs(tree[u][i].first,u,tree[u][i].second);
}

int lca(int u, int v) {
    ansMax=-INF;
    ansMin=INF;
    if(depth[u]<depth[v])
        swap(u,v);
    for(int i=l-1;i>=0;i--) {
        if(parent[u][i]!=-1 && depth[parent[u][i]]>=depth[v]) {
            ansMax=max(ansMax,maxR[u][i]);
            ansMin=min(ansMin,minR[u][i]);
            u=parent[u][i];
        }
    }
    if(u==v)
        return u;
    for(int i=l-1;i>=0;i--) {
        if(parent[u][i]!=parent[v][i]) {
            ansMax=max(ansMax,maxR[u][i]);
            ansMin=min(ansMin,minR[u][i]);
            ansMax=max(ansMax,maxR[v][i]);
            ansMin=min(ansMin,minR[v][i]);
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    ansMax=max(ansMax,maxR[u][0]);
    ansMin=min(ansMin,minR[u][0]);
    ansMax=max(ansMax,maxR[v][0]);
    ansMin=min(ansMin,minR[v][0]);
    return parent[u][0];
}

void init() {
    l=(int)ceil(log(N)/log(2));
    for(int i=0;i<n;i++) {
        for(int j=0;j<l;j++) {
            parent[i][j]=-1;
            maxR[i][j]=-INF;
            minR[i][j]=INF;
        }
    }
    dfs(0,-1,0);

}

int main() {
    cin >> n;
    for(int i=0;i<n-1;i++) {
        cin >> a >> b >> c;
        a--,b--;
        tree[a].pb(mp(b,c));
        tree[b].pb(mp(a,c));
    }
    init();
    cin >> k;
    for(int j=0;j<k;j++) {
        cin >> d >> e;
        d--,e--;
        lca(d,e);
        cout << ansMin << " " << ansMax << endl;
    }
}
