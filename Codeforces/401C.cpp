#include <bits/stdc++.h>
using namespace std;
int n,m;

int main() {
    cin >> n >> m;
    if (n>m+1 || m>2*n+2) return 0*printf("-1\n");
    if (n>=m) {
        for (int i=0;i<m;i++) cout <<"01";
        if (n>m) cout <<"0";
        cout << endl;
        return 0;
    }
    while(n!=m && m>=2 && n) {
        cout << "110";
        n--;m-=2;
    }
    if (!n&&m==1) cout <<"1";
    else if (!n && m==2) cout << "11";
    else
        for (int i=0;i<n;i++) cout << "10";
    cout << endl;
}
