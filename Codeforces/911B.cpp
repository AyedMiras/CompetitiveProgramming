#include <bits/stdc++.h>
using namespace std;

int a,b,n;

bool isValid(int x) {
    if (a/x == 0 || b/x ==0) return 0;
    return a/x + b/x >=n?1:0;
}

int main() {
    cin >> n >> a >> b;
    int l=1,r=201;
    while(l<r) {
        int mid = l +(r-l)/2;
        isValid(mid)?l=mid+1:r=mid;
    }
    cout << r-1 << endl;
}
