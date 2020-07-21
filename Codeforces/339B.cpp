#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,m,a[N];
long long int res;

int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) cin >> a[i],a[i]--;
    int pos=0;
    for (int i=0;i<m;i++) {
        if (pos<= a[i]) res+=a[i]-pos;
        else res+=(n-pos) + a[i];
        pos = a[i];
    }
    cout << res << endl;
}
