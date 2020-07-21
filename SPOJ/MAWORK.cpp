#include <bits/stdc++.h>
using namespace std;
const int N=25;
const int PPCM=2520;
int T,n;
int dx[5]= {0,0,0,1,-1};
int dy[5]= {0,1,-1,0,0};
char grid[N][N],schd[N][N];
int dist[N][N][PPCM];

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<n;
}

char inv(char c){
    if (c=='.') return '*';
    if (c=='*') return '.';
}

bool isWalkable(char c){
    if (c=='.')
        return 1;
    return 0;
}

int bfs(){
    queue<tuple<int,int,int> > q;
    dist[0][0][0]=0;
    q.push(make_tuple(0,0,0));
    while(!q.empty()){
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int mask = get<2>(q.front());
        q.pop();
        if (i==n-1 && j==n-1)
            return dist[i][j][mask];
        for (int k=0;k<5;k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            int nmask = (mask+1)%PPCM;
            if (isValid(ii,jj) &&
                dist[ii][jj][nmask]==-1 &&
                    ( (schd[ii][jj]=='0' && isWalkable(grid[ii][jj]) ) ||
                        ( (schd[ii][jj]-'0') &&
                            ( (nmask/(schd[ii][jj]-'0'))&1?isWalkable(inv(grid[ii][jj])):isWalkable(grid[ii][jj])))))
                q.push(make_tuple(ii,jj,nmask)),dist[ii][jj][nmask]=dist[i][j][mask]+1;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        memset(dist,-1,sizeof(dist));
        cin >> n;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> grid[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> schd[i][j];
        int res = bfs();
        if (res!=-1)
            cout << res << endl;
        else
            cout << "NO" << endl;
    }
}
