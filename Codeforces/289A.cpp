#include <bits/stdc++.h>
using namespace std;
int n,k,l,r,cnt;

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> l >> r,cnt+=r-l+1;
    cout << (k - cnt%k)%k << endl;
}
