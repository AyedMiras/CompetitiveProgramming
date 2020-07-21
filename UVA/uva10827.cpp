#include <bits/stdc++.h>
using namespace std;
const int INF  = -1000000;
int T,n,torus[200][200],cum[200][200];

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> torus[i][j],torus[i+n][j]=torus[i][j+n]=torus[i+n][j+n]=torus[i][j];
        for (int i=0;i<2*n;i++){
            for (int j=0;j<2*n;j++){
                cum[i][j] = torus[i][j];
                if (i>0) cum[i][j]+=cum[i-1][j];
                if (j>0) cum[i][j]+=cum[i][j-1];
                if (i>0 && j>0) cum[i][j]-=cum[i-1][j-1];
            }
        }
        int m = INF;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                for (int k=i;k<i+n;k++) {
                    for (int l=j;l<j+n;l++) {
                        int c = cum[k][l];
                        if (i>0) c-=cum[i-1][l];
                        if (j>0) c-=cum[k][j-1];
                        if (i>0 && j>0) c+=cum[i-1][j-1];
                        m = max(m,c);
                    }
                }
            }
        }
        cout << m << endl;
    }
}
