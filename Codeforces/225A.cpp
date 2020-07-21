#include <bits/stdc++.h>
using namespace std;
int n,top,a,b;
bool flag;

int main() {
    cin >> n >> top;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        if (a!=top && b!=top && a!=7-top && b!=7-top) continue;
        flag = true;
    }
    if (flag) cout << "NO" << endl;
    else cout << "YES" << endl;
}
