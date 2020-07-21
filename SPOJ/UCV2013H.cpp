#include <bits/stdc++.h>
using namespace std;
const int N=300;
int n,m,grid[N][N],vis[N][N],vid;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
map<int,int> cnt;

bool isValid(int i,int j){
    return (i>=0 && j>=0 && i<n && j<m);
}

void bfs(int si, int sj) {
    int oil=0;
    queue<pair<int,int> > q;
    vis[si][sj]=vid;
    q.push(make_pair(si,sj));
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        oil++;
        for(int k=0;k<4;k++){
            int ii= i+dx[k];
            int jj= j+dy[k];
            if (isValid(ii,jj) && vis[ii][jj]!=vid && grid[ii][jj]) {
                vis[ii][jj]=vid;
                q.push(make_pair(ii,jj));
            }
        }
    }
    if (oil)
        cnt[oil]++;
}

int main(){
    while(1){
        cin >> n >> m;
        if (!n && !m)
            return 0;
        vid++;
        cnt.clear();
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> grid[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (vis[i][j]!=vid && grid[i][j])
                    bfs(i,j);
        int occ=0;
        for (map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it)
            occ+=it->second;
        cout << occ << endl;
        for (map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it)
            cout << it->first << " " << it->second << endl;
    }
}
