#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=200200;
vector<vector<int>> graph(N);
bool vis[N];
int n;
ll res;

int dfs(int src){
    int ed=0;
    vis[src]=1;
    for (int i=0;i<graph[src].size();i++)
        if (!vis[graph[src][i]])
            ed+=dfs(graph[src][i]);
    return ed+graph[src].size();
}

int main() {
    cin >> n;
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    res+=dfs(0);
    cout << res << endl;
}
