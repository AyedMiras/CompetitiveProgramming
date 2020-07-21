#include <bits/stdc++.h>
using namespace std;
int n,m,k;

int main() {
    cin >> n >> m >> k;
    int cnt=0;
    for (int i=1;i<=n;i++) {
        if (i&1)
            for (int j=1;j<=m;j++) {
                if (!cnt && k==1) cout << n*m - (i-1)*m -j +1;
                if (!cnt && k>1) cout << 2;
                cout << " " << i << " " << j,cnt++;
                if (cnt==2 && k>1) cout << endl,k--,cnt=0;
            }
        else {
            for (int j=m;j>=1;j--) {
                if (!cnt && k==1) cout << n*m - (i-1)*m - m +j;
                if (!cnt && k>1) cout << 2;
                cout << " " << i << " " << j,cnt++;
                if (cnt==2 && k>1) cout << endl,k--,cnt=0;
            }
        }
    }
    cout << endl;
}
