#include <bits/stdc++.h>
using namespace std;
int n,m,s,mark[110];
char grid[110][110];

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> grid[i][j];
    for (int j=0;j<m;j++)
        for(int i=0;i<n;i++)
            mark[j] = max(mark[j],grid[i][j]-'0');
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if ( (grid[i][j]-'0')==mark[j]) {
                s++;
                break;
            }
        }
    }
    cout << s << endl;
}
