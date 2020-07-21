#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
const int N=110;
const int INF=0x3f3f3f3f;
int n,m,dist[N],vis[N][N],parent[N];
vii graph[N];

int dijkstra() {
    priority_queue<ii,vii,greater<ii>> pq;
    pq.push(mp(0,0));
    dist[0]=0;
    while(!pq.empty()) {
        int currD=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(u==n-1)
            return currD;
        for(int i=0;i<graph[u].size();i++) {
            int v=graph[u][i].first;
            int w=graph[u][i].second;
            if(!vis[u][v] && currD+w<dist[v]) {
                dist[v]=currD+w;
                parent[v]=u;
                pq.push(mp(dist[v],v));
            }
        }
    }
    return -1;
}

void init() {
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<N;i++)
        graph[i].clear();
}

int main() {
    while(1) {
        cin >> n;
        if(!n)
            return 0;
        cin >> m;
        init();
        for(int i=0;i<m;i++) {
            int u,v,w;
            cin >> u >> v >> w;
            u--,v--;
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        int res1=dijkstra();
        memset(dist,0x3f,sizeof(dist));
        int i=n-1;
        while(parent[i]!=-1) {
            vis[parent[i]][i]=1;
            for(int k=0;k<graph[i].size();k++)
                if(graph[i][k].first==parent[i])
                    graph[i][k].second*=-1;
            i=parent[i];
        }
        int res2=dijkstra();
        if (res1==-1 || res2==-1)
            cout << "Back to jail" << endl;
        else
            cout << res1+res2 << endl;
    }
}
