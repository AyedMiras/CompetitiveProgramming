#include <bits/stdc++.h>
using namespace std;
const int N=55;
const int M =11;
int T,n,cnt,si,sj,ei,ej;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int grid[N][N];
int vis[N][N][1<<M];
map<int,int> ind;

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<n;
}

int bits(int m) {
    int b=0;
    for (int i=1;i<=cnt;i++)
        if ((1<<i)&m)
            b++;
    return b;
}

int bfs() {
    int res = cnt;
    queue<tuple<int,int,int> > q;
    vis[si][sj][1<<ind[grid[si][sj]]]=1;
    q.push(make_tuple(si,sj,1<<ind[grid[si][sj]]));
    while(!q.empty()){
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int mask = get<2>(q.front());
        if (i==ei && j==ej)
            res = min(res,bits(mask));
        q.pop();
        for (int k=0;k<4;k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            if (isValid(ii,jj) && !vis[ii][jj][mask]){
                if ( (1<<ind[grid[ii][jj]])&mask ) {
                    vis[ii][jj][mask]=1;
                    q.push(make_tuple(ii,jj,mask));
                }
                else {
                    int nmask = (1<<ind[grid[ii][jj]])|mask;
                    vis[ii][jj][nmask]=1;
                    vis[ii][jj][mask]=1;
                    q.push(make_tuple(ii,jj,nmask));
                }
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--) {
        ind.clear();
        cnt=0;
        memset(vis,0,sizeof(vis));
        cin >> n;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> grid[i][j];
                if (!ind[grid[i][j]])
                    ind[grid[i][j]]=++cnt;
            }
        }
        cin >> si >> sj >> ei >> ej;
        cout << bfs() << endl;
    }
}
