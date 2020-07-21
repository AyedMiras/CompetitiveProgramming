#include <bits/stdc++.h>
using namespace std;
const int N=16;
const int M=12;
int r,c,w,si,sj,sk,coins;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char world[N][N][M];
int dist[N][N][M][1<<M];
bool vis[N][N][M][1<<M];
map<tuple<int,int,int>,int > ind;

bool isValid(int i, int j){
    return i>=0 && j>=0 && i<r && j<c;
}

int bfs() {
    queue<tuple<int,int,int,int> > q;
    dist[si][sj][sk][0]=0;
    vis[si][sj][sk][0]=1;
    q.push(make_tuple(si,sj,sk,0));
    while(!q.empty()){
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int k = get<2>(q.front());
        int mask = get<3>(q.front());
        q.pop();
        if (world[i][j][k]=='M') {
            if (mask==((1<<coins)-1))
                return dist[i][j][k][mask];
            continue;
        }
        if (world[i][j][k]=='#')
            continue;
        if (world[i][j][k]=='C') {
            int nmask = (1<<ind[make_tuple(i,j,k)])|mask;
            if (vis[i][j][k][nmask])
                continue;
            dist[i][j][k][nmask]=dist[i][j][k][mask];
            vis[i][j][k][nmask]=1;
            mask = nmask;
        }
        if (world[i][j][k]=='D') {
            if (k==w-1)
                continue;
            if (vis[i][j][k+1][mask])
                continue;
            dist[i][j][k+1][mask]=dist[i][j][k][mask];
            vis[i][j][k+1][mask]=1;
            q.push(make_tuple(i,j,k+1,mask));
            continue;
        }
        if (world[i][j][k]=='U') {
            if (!k)
                continue;
            if (vis[i][j][k-1][mask])
                continue;
            dist[i][j][k-1][mask]=dist[i][j][k][mask];
            vis[i][j][k-1][mask]=1;
            q.push(make_tuple(i,j,k-1,mask));
            continue;
        }
        for (int l=0;l<4;l++){
            int ii = i+dx[l];
            int jj = j+dy[l];
            if (isValid(ii,jj) && world[ii][jj][k]!='#' && !vis[ii][jj][k][mask]) {
                if (world[ii][jj][k]=='C') {
}
                dist[ii][jj][k][mask]=dist[i][j][k][mask]+1;
                vis[ii][jj][k][mask]=1;
                q.push(make_tuple(ii,jj,k,mask));
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    while(1) {
        cin >> r >> c >> w;
        if (!r && !c && !w)
            return 0;
        memset(dist,-1,sizeof(dist));
        memset(vis,0,sizeof(vis));
        ind.clear();
        coins=0;
        for (int k=0;k<w;k++) {
            for (int i=0;i<r;i++) {
                for (int j=0;j<c;j++) {
                    cin >> world[i][j][k];
                    if (world[i][j][k]=='S')
                        si=i,sj=j,sk=k;
                    if (world[i][j][k]=='C')
                        ind[make_tuple(i,j,k)]=coins++;
                }
            }
        }
        int res = bfs();
        if (res==-1)
            cout << "Mario failed to save princess" << endl;
        else
            cout << "Mario saved the princess in " << res << " steps" << endl;
    }
}
