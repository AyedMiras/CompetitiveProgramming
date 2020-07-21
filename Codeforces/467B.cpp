#include <bits/stdc++.h>
using namespace std;
const int M = 1010;
int n,m,k,p[M];

int main() {
    cin >> n >> m >> k;
    for (int i=0;i<=m;i++) cin >> p[i];
    int fr=0;
    for (int i=0;i<m;i++) {
        int cnt=0;
        for (int j=0;j<n;j++)
            if ( ((1<<j)&p[i])  != ((1<<j)&p[m])) cnt++;
        if (cnt<=k) fr++;
    }
    cout << fr << endl;
}
