#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,L,a,br,t[N],d[N];

int main() {
    cin >> n >> L >> a;
    for (int i=1;i<=n;i++)
        cin >> t[i] >> d[i];
    t[n+1]=L;
    for (int i=1;i<=n+1;i++)
        br+=(t[i]-t[i-1]-d[i-1])/a;
    cout << br << endl;

}
