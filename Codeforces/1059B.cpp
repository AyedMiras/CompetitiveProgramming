#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
char grid[N][N];
bool inked[N][N];

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> grid[i][j];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            int flag=1;
            for (int k=0;k<8;k++)
                if (!isValid(i+dx[k],j+dy[k]) || grid[i+dx[k]][j+dy[k]]!='#')
                    flag=0;
            if (flag)
                for (int k=0;k<8;k++)
                    inked[i+dx[k]][j+dy[k]]=1;
        }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (grid[i][j]=='#' && !inked[i][j])
                return 0*printf("NO\n");
    cout << "YES" << endl;
}
