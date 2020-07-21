#include <bits/stdc++.h>
using namespace std;
const int N = 550;
int n,m,q,x,y,grid[N][N],row[N];

int main() {
    cin >> n >> m >> q;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> grid[i][j];
    for (int i=0;i<n;i++) {
        int cnt=0,m4x=0;
        for (int j=0;j<m;j++) {
            if (!grid[i][j]) cnt=-1;
            cnt++;
            m4x = max(m4x,cnt);
        }
        row[i]=m4x;
    }
    for (int i=0;i<q;i++) {
        cin >> x >> y;
        grid[--x][--y] = 1-grid[x][y];
        int cnt=0,m4x=0;
        for (int j=0;j<m;j++) {
            if (!grid[x][j]) cnt=-1;
            cnt++;
            m4x = max(m4x,cnt);
        }
        row[x] = m4x;
        m4x = 0;
        for (int j=0;j<n;j++)
            m4x = max(m4x,row[j]);
        cout << m4x << endl;
    }
}
