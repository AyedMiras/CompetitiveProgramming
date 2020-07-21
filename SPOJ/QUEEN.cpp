#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int T,n,m,si,sj,fi,fj;
int dist[N][N];
char grid[N][N];
int dx[8];
int dy[8];

int isValid(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

void init() {
    int ind=0;
    for (int i=-1;i<=1;i++)
        for (int j=-1;j<=1;j++)
            if (i || j)
                dx[ind]=i,dy[ind++]=j;
}

int bfs() {
    queue<pair<int,int> > q;
    dist[si][sj]=0;
    q.push(make_pair(si,sj));
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if (i==fi && j==fj)
            return dist[i][j];
        for (int k=0;k<8;k++){
            int ii=i;
            int jj=j;
            if (!(isValid(ii+dx[k],jj+dy[k]) && grid[ii+dx[k]][jj+dy[k]]!='X' && dist[ii+dx[k]][jj+dy[k]]==-1))
                continue;
            while(isValid(ii+dx[k],jj+dy[k]) && grid[ii+dx[k]][jj+dy[k]]!='X' && dist[ii+dx[k]][jj+dy[k]]==-1) {
                ii+=dx[k],jj+=dy[k];
                dist[ii][jj]=dist[i][j]+1;
                if (grid[ii][jj]=='F')
                    break;
            }
            q.push(make_pair(ii,jj));
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    init();
    cin >> T;
    while(T--) {
        memset(dist,-1,sizeof(dist));
        cin >> n >> m;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                cin >> grid[i][j];
                if (grid[i][j]=='S')
                    si=i,sj=j;
                if (grid[i][j]=='F')
                    fi=i,fj=j;
            }
        cout << bfs() << endl;
    }
}
