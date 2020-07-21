#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 +100;
int n,m,t[N];

bool isValid(int h) {
    long long int s=0;
    for (int i=0;i<n;i++) {
        if (t[i]>h)
            s+= t[i]-h;
    }
    return (s>=m);
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> t[i];
    sort(t,t+n);
    int l=0,r=(int)2e9 + 1;
    while(l<r) {
        int mid = l +(r-l)/2;
        if (isValid(mid)) {
            l = mid +1;
        }
        else
            r = mid;
    }
    cout << r-1 <<  endl;
}
