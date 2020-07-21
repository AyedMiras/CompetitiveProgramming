#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int P=11;
int n,m,p;
char grid[N][N];
int vis[N][N],castle[N],s[P];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<tuple<int,int,int>> q;

bool isValid(int i,int j) {
    return i>=0 && j>=0 && i<n && j<m;
}


void expand(int u, int v, int ind) {
    queue<pair<int,int>> qq;
    int depth[N][N];
    qq.push(make_pair(u,v));
    depth[u][v]=0;
    while(!qq.empty()) {
        int i=qq.front().first;
        int j=qq.front().second;
        qq.pop();
        if(depth[i][j]>=s[ind])
            continue;
        for(int k=0;k<4;k++) {
            int ii=i+dx[k];
            int jj=j+dy[k];
            if(isValid(ii,jj) && !vis[ii][jj] && grid[ii][jj]=='.') {
                vis[ii][jj]=1;
                grid[ii][jj]='1'+ind;
                castle[ind]++;
                depth[ii][jj]=depth[i][j]+1;
                qq.push(make_pair(ii,jj));
                q.push(make_tuple(ii,jj,ind));
            }
        }
    }
}

void bfs() {
    for(int k=0;k<p;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]=='1'+k)
                    q.push(make_tuple(i,j,k)),
                    vis[i][j]=1,
                    castle[k]++;
    while(!q.empty()) {
        int i=get<0>(q.front());
        int j=get<1>(q.front());
        int ind=get<2>(q.front());
        q.pop();
        expand(i,j,ind);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> p;
    for(int i=0;i<p;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    bfs();
    for(int i=0;i<p;i++)
        cout << castle[i] << " \n"[i==p-1];
}
