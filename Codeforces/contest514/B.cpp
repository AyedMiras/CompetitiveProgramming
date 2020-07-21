#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
char grid[N][N],nGrid[N][N];
bool inked[N][N];

bool isValid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int main() {
    memset(inked,1,sizeof(inked));
    cin >> n >> m;
    bool flag=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j]=='.')
                flag=1;
        }
    //if (n==3 && m==3 && !flag)
      //  return 0*printf("NO\n");
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (grid[i][j]=='.')
                for (int k=0;k<8;k++)
                    if (isValid(i+dx[k],j+dy[k]))
                        inked[i+dx[k]][j+dy[k]]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            nGrid[i][j]='.';
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (inked[i][j]) {
                int cnt=0;
                for (int k=0;k<8;k++) {
                    if (isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='#') {
                        cnt++;
                    }
                }
                if (cnt==8)
                    for (int k=0;k<8;k++)
                        nGrid[i+dx[k]][j+dy[k]]='#';
            }
        }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (grid[i][j]!=nGrid[i][j])
                return 0*printf("NO\n");
    cout << "YES" << endl;
}
