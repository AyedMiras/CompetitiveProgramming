#include <bits/stdc++.h>
using namespace std;
const int N=200;
int n,m,T,vis[N][N],dist[N][N];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char grid[N][N];
queue<pair<int,int> > q;

int isValid(int i,int j) {
    return (i>=0 && j>=0 && i<n && j<m);
}

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> m;
        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> grid[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (grid[i][j]-'0')
                    q.push(make_pair(i,j)),vis[i][j]=1;

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k=0;k<4;k++) {
                int ii = i+dx[k];
                int jj = j+dy[k];
                if (isValid(ii,jj) && !vis[ii][jj])
                    q.push(make_pair(ii,jj)),vis[ii][jj]=1,dist[ii][jj] = dist[i][j]+1;
            }
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cout << dist[i][j] << " \n"[j==m-1];
    }
}
