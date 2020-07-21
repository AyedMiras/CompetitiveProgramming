#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
int n,m;
long long int cnt,a[N],b[N];

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) a[i%5]++;
    for (int i=1;i<=m;i++) b[i%5]++;
    cnt = a[0]*b[0];
    for (int i=0;i<5;i++) cnt+=a[i]*b[5-i];
    cout << cnt << endl;
}
