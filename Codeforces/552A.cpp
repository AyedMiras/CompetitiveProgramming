#include <bits/stdc++.h>
using namespace std;
int n,x1,x2,y1,y2;
int grid[110][110];

int main() {
    cin >> n;
    for (int k=0;k<n;k++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i=x1;i<=x2;i++)
            for (int j=y1;j<=y2;j++)
                grid[i-1][j-1]++;
    }
    int s=0;
    for (int i=0;i<100;i++)
        for (int j=0;j<100;j++)
            s+=grid[i][j];
    cout << s << endl;
}
