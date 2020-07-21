#include <bits/stdc++.h>
using namespace std;
int n,m,b[110][110],a[110][110];
bool row[110],col[110];

int main() {
    cin >> m >> n;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            cin >> b[i][j];
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (!b[i][j])
                row[i]=col[j]=true;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (row[i] && col[j] && b[i][j])
                return 0*printf("NO\n");
            if (!row[i] && !col[j])
                a[i][j]=1;
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            int x=0;
            for (int k=0;k<n;k++)
                x|=a[i][k];
            for (int k=0;k<m;k++)
                x|=a[k][j];
            if (x!=b[i][j])
                return 0*printf("NO\n");
        }
    }

    cout << "YES" << endl;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            cout << a[i][j] << " \n"[j==n-1];

}
