#include <bits/stdc++.h>
using namespace std;
const int INF = -(25*25);
int T,n;
int mat[30][30],cum[30][30];
string line;

int main() {
    cin >> T;
    cin.ignore();
    getline(cin, line);
    while(T--) {
        int i=0;
        while(getline(cin, line) && line.length()) {
            for (int j=0;j<line.length();j++)
                mat[i][j] = line[j]-'0';
            i++;
            n = line.length();
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cum[i][j]= mat[i][j];
                if (i>0) cum[i][j]+= cum[i-1][j];
                if (j>0) cum[i][j]+= cum[i][j-1];
                if (i>0 && j>0) cum[i][j]-= cum[i-1][j-1];
            }
        }
        int m = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                for (int k=i;k<n;k++) {
                    for (int l=j;l<n;l++) {
                        int r = cum[k][l];
                        if (i>0) r-=cum[i-1][l];
                        if (j>0) r-=cum[k][j-1];
                        if (i>0 && j>0) r+=cum[i-1][j-1];
                        if (r == (k-i+1)*(l-j+1))
                            //cout << i << " " << j << " " << k << " " << l << endl;
                            m = max(m,r);
                    }
                }
            }
        }
        cout << m << endl;
        if (T) cout << endl;
    }
}
