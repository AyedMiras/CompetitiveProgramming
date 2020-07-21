#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int M=(int)ceil(log2(N));
int T,n,q,m,w1,w2,l,timer,tin[N],tout[N],parent[N][M];
vector<int> graph[N];

void dfs(int u, int p) {
    tin[u]=timer++;
    parent[u][0]=p;
    for(int i=1;i<=l;i++)
        parent[u][i]=parent[parent[u][i-1]][i-1];
    for(int i=0;i<graph[u].size();i++)
        if(graph[u][i]!=p)
            dfs(graph[u][i],u);
    tout[u]=timer++;
}

bool isAncestor(int u, int v) {
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v) {
    if(isAncestor(u,v))
        return u;
    if(isAncestor(v,u))
        return v;
    for(int i=l-1;i>=0;i--)
        if(!isAncestor(parent[u][i],v))
            u=parent[u][i];
    return parent[u][0];
}

void init() {
    for(int i=0;i<n;i++)
        graph[i].clear();
    l=(int)ceil(log2(n));
    timer=0;
}

int main() {
    cin >> T;
    for(int t=1;t<=T;t++) {
        cout << "Case " << t << ":" << endl;
        cin >> n;
        init();
        for(int i=0;i<n;i++) {
            cin >> m;
            for(int j=0;j<m;j++) {
                cin >> w1;
                graph[i].push_back(w1-1);
                graph[w1-1].push_back(i);
            }
        }
        dfs(0,0);
        cin >> q;
        for(int i=0;i<q;i++) {
            cin >> w1 >> w2;
            cout << lca(w1-1,w2-1)+1 << endl;
        }
    }
    return 0;
}
