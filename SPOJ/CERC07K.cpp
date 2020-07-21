#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int MASK = 16;
int r,c,si,sj;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dist[N][N][MASK];
char grid[N][N];
bool vis[N][N][MASK];
bool flag;
queue<tuple<int,int,int> > q;
map<char,int> ind;

bool isValid(int i,int j) {
    return i>=0 && j>=0 && i<r && j<c;
}

void init() {
    ind['r']=ind['R']=0;
    ind['b']=ind['B']=1;
    ind['g']=ind['G']=2;
    ind['y']=ind['Y']=3;
}

bool isWalkable(char ch) {
    return (ch=='.') || (ch=='X') || (ch=='*');
}

bool isUpper(char ch) {
    return ch>='A' && ch<='Z';
}

bool isLower(char ch) {
    return ch>='a' && ch<='z';
}

int main() {
    init();
    ios::sync_with_stdio(0);
    while(1) {
        cin >> r >> c;
        if (!r && !c) return 0;
        flag = 0;
        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
        q = queue<tuple<int,int,int> >();
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*')
                    si = i, sj=j;
            }
        }
        q.push(make_tuple(si,sj,0));
        vis[si][sj][0]=1;
        while(!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int mask = get<2>(q.front());
            q.pop();
            if (grid[i][j]=='X') {
                cout << "Escape possible in " << dist[i][j][mask] << " steps." << endl;
                flag = 1;
                break;
            }
            for (int k=0;k<4;k++) {
                int ii = i+dx[k];
                int jj = j+dy[k];
                if (isValid(ii,jj) && grid[ii][jj]!='#' && !vis[ii][jj][mask]) {
                    if ( isWalkable(grid[ii][jj]) || (isUpper(grid[ii][jj]) && (1<<ind[grid[ii][jj]])&mask ) ) {
                        vis[ii][jj][mask]=1;
                        dist[ii][jj][mask]=dist[i][j][mask]+1;
                        q.push(make_tuple(ii,jj,mask));
                    }
                    else if (isLower(grid[ii][jj])) {
                        int nmask = (1<<ind[grid[ii][jj]])|mask;
                        if (vis[ii][jj][nmask]) continue;
                        vis[ii][jj][nmask]=1;
                        vis[ii][jj][mask]=1;
                        dist[ii][jj][nmask]=dist[i][j][mask]+1;
                        dist[ii][jj][mask]=dist[i][j][mask]+1;
                        q.push(make_tuple(ii,jj,nmask));
                    }
                }
            }
        }
        if (!flag)
            cout << "The poor student is trapped!" << endl;
    }
}
