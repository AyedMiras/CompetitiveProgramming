#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,m,b,a[N],ind[N];
long long int v,p;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i], ind[a[i]]=i;
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> b;
        v+=ind[b]+1,p+=n-ind[b];
    }
    cout << v << " " << p << endl;
}
