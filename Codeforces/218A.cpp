#include <bits/stdc++.h>
using namespace std;
int n,k,r[210],cnt;

int main() {
    cin >> n >> k;
    for (int i=0;i<2*n+1;i++) {
        cin >> r[i];
    }
    cout << r[0];
    for (int i=1;i<2*n+1;i++) {
        if (i&1 && cnt<k && r[i]-1>r[i-1] && r[i]-1>r[i+1]) cout << " " << --r[i],cnt++;
        else cout << " " << r[i];
    }
    cout << endl;
}
