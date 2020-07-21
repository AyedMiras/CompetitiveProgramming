#include <bits/stdc++.h>
using namespace std;
int c[5],s;

int main() {
    for (int i=0;i<5;i++)
        cin >> c[i],s+=c[i];
    if (s%5 || !s) cout << -1;
    else cout << s/5;
    cout << endl;

}
