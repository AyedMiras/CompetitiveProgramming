#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N],res;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    int l=0,r=0;
    while(l<n) {
        res=max(res,r-l+1);
        l++;
    }
    cout << res << endl;
}
