#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010],occ[1010];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i],occ[a[i]]++;
    for (int i=0;i<1010;i++)
        m = max(occ[i],m);
    cout << (m> n/2+(n&1)?"NO":"YES") << endl;
}
