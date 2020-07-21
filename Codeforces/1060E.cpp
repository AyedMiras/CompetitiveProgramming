#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=200200;
ll n,subTree[N],vis[N],cnt,o,z;
vector<vector<int>> graph(N);

int dfs(int src, bool flag){
    vis[src]=1;
    flag?o++:z++;
    for (int i=0;i<graph[src].size();i++)
        if (!vis[graph[src][i]])
            subTree[src]+=dfs(graph[src][i],1-flag);
    return ++subTree[src];
}

void dfs(int src){
    vis[src]=1;
    for (int i=0;i<graph[src].size();i++) {
        if (!vis[graph[src][i]]) {
            cnt+=subTree[graph[src][i]]*(n-subTree[graph[src][i]]);
            dfs(graph[src][i]);
        }
    }
}

int main(){
    cin >> n;
    for (int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0,0);
    memset(vis,0,sizeof(vis));
    dfs(0);
    cout << (cnt+o*z)/2 << endl;
}
