#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=2020;
int n,m,k;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int x[10],y[10];
int vis[N][N],dist[N][N];
pii res;

bool isValid(int i,int j) {
    return i>=0 && j>=0 && i<n && j<m;
}

void bfs() {
    queue<pii> q;
    for (int i=0;i<k;i++) {
        q.push(make_pair(x[i],y[i]));
        vis[x[i]][y[i]]=1;
    }
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        res.first = i, res.second = j;
        q.pop();
        for (int k=0;k<4;k++) {
            int ii = i+dx[k];
            int jj = j+dy[k];
            if (isValid(ii,jj) && !vis[ii][jj]) {
                vis[ii][jj]=1;
                dist[ii][jj] = dist[i][j]+1;
                q.push(make_pair(ii,jj));
            }
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    for (int i=0;i<k;i++) cin >> x[i] >> y[i],x[i]--,y[i]--;
    bfs();
    cout << ++res.first << " " << ++res.second << endl;
}
