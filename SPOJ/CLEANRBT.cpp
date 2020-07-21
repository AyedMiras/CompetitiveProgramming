#include <bits/stdc++.h>
using namespace std;
const int N=22;
const int M=11;
int w,h,si,sj,cnt;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dist[N][N][1<<M];
char grid[N][N];
map<int,int> ind;

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<h && j<w;
}

int bfs() {
    queue<tuple<int,int,int> > q;
    dist[si][sj][0]=0;
    q.push(make_tuple(si,sj,0));
    while(!q.empty()) {
        int i= get<0>(q.front());
        int j= get<1>(q.front());
        int mask = get<2>(q.front());
        q.pop();
        if (mask == ((1<<cnt)-1))
            return dist[i][j][mask];
        for (int k=0;k<4;k++) {
            int ii = i+dx[k];
            int jj = j+dy[k];
            if (isValid(ii,jj) && grid[ii][jj]!='x' && dist[ii][jj][mask]==-1) {
                if (grid[ii][jj]=='*'){
                    int nmask = (1<<ind[ii+h*jj])|mask;
                    q.push(make_tuple(ii,jj,nmask));
                    dist[ii][jj][nmask]=dist[i][j][mask]+1;;
                    dist[ii][jj][mask]=dist[i][j][mask]+1;
                }
                else {
                    q.push(make_tuple(ii,jj,mask));
                    dist[ii][jj][mask]=dist[i][j][mask]+1;
                }
            }
        }
    }
    return -1;
}

int main() {
    while(1) {
        cin >> w >> h;
        if (!w && !h)
            return 0;
        memset(dist,-1,sizeof(dist));
        cnt = 0;
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                cin >> grid[i][j];
                if (grid[i][j]=='o')
                    si = i,sj =j;
                if (grid[i][j]=='*')
                    ind[i+h*j]=cnt++;
            }
        }
        cout << bfs() << endl;
    }
}

