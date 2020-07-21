#include <bits/stdc++.h>
using namespace std;
const int N=22;
int T,m,n,vid,si,sj,ei,ej;
char grid[N][N];
int vis[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<m && j<n;
}

bool bfs() {
    queue<pair<int,int> > q;
    vis[si][sj]=vid;
    q.push(make_pair(si,sj));
    while(!q.empty()) {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if (i==ei && j==ej)
            return 1;
        for (int k=0;k<4;k++) {
            int ii=i+dx[k];
            int jj=j+dy[k];
            if (isValid(ii,jj) && grid[ii][jj]=='.' && vis[ii][jj]!=vid ){
                vis[ii][jj]=vid;
                q.push(make_pair(ii,jj));
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        vid++;
        cin >> m >> n;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                cin >> grid[i][j];
        int cnt=0;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if ((!i || !j || i==m-1 || j==n-1) && grid[i][j]=='.') {
                    if (!cnt)
                        si=i,sj=j;
                    else
                        ei=i,ej=j;
                    cnt++;
                }
        if (cnt!=2) {
            cout << "invalid" << endl;
            continue;
        }
        cout << (bfs()?"valid":"invalid") << endl;
    }
}
