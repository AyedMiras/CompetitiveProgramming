#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,q,sqr,mat[N][N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            scanf("%d",&(mat[i][j]));
    for (int i=0;i<n;i++)
        sqr+=mat[i][i];
    sqr = sqr%2;
    scanf("%d",&q);
    while(q--){
        int i,j;
        scanf("%d",&i);
        if (i==1 || i==2) {
            scanf("%d",&j);
            mat[j][j] = 1 - mat[j][j];
            sqr = 1-sqr;
        }
        else
            printf("%c",sqr+'0');
    }
    printf("\n");
}
