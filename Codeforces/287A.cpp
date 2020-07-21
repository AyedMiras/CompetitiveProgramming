#include <bits/stdc++.h>
using namespace std;
char grid[4][4];
int dx[4]= {0,0,1,1};
int dy[4]= {0,1,0,1};

bool possible(int i, int j) {
    int cnt = 0;
    for (int k=0;k<4;k++)
        cnt+=grid[i+dx[k]][j+dy[k]]=='.';
    return cnt!=2;
}

int main() {
    for (int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> grid[i][j];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (possible(i,j))
               return 0*printf("YES\n");
    printf("NO\n");
}
