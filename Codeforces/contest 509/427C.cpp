#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
const int MOD=(int)1e9+7;
int n,m,ind;
ll cost[N];
vector<int> graph[N],Rgraph[N],scc[N];
stack<int> s;
bool vis[N];

void dfs(int u) {
    vis[u]=1;
    for (int i=0;i<graph[u].size();i++)
        if (!vis[graph[u][i]])
            dfs(graph[u][i]);
    s.push(u);
}

void dfsUtil(int u) {
    vis[u]=1;
    scc[ind-1].push_back(u);
    for (int i=0;i<Rgraph[u].size();i++) {
        if (!vis[Rgraph[u][i]])
            dfsUtil(Rgraph[u][i]);
    }
}

void computeReverseGraph() {
    for (int i=0;i<n;i++)
        for (int j=0;j<graph[i].size();j++)
            Rgraph[graph[i][j]].push_back(i);
}

void computeSCC() {
    for (int i=0;i<n;i++)
        if (!vis[i])
            dfs(i);
    computeReverseGraph();
    memset(vis,0,sizeof(vis));
    while(!s.empty()){
        if (!vis[s.top()])
            ++ind,dfsUtil(s.top());
        s.pop();
    }
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> cost[i];
    cin >> m;
    for (int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
    }
    computeSCC();
    ll totalCost=0,nb=1;
    for (int i=0;i<ind;i++){
        ll m1n=0x3f3f3f3f,cnt=0;
        for (int j=0;j<scc[i].size();j++)
            m1n = min(m1n,cost[scc[i][j]]);
        for (int j=0;j<scc[i].size();j++)
            if (cost[scc[i][j]]==m1n)
                cnt++;
        totalCost+=m1n;
        nb=(nb*cnt)%MOD;
    }
    cout << totalCost << " " << nb << endl;
}
