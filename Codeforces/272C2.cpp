#include <bits/stdc++.h>
using namespace std;
const int N=100100;
long long int n,m,h,w,W,H,a[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> w >> h;
        cout << (w<W?H:max(H,a[w-1])) << endl;
        if (w<W)
            H = H+h;
        else {
            W = w;
            H = max(a[w-1],H)+h;
        }
    }
}
