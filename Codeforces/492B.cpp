#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,l,a[N];

bool isValid(double d) {
    for (int i=0;i<n-1;i++)
        if (a[i]+d <a[i+1]-d)
            return 0;
    if (a[n-1]+d <l)
        return 0;
    return 1;
}

double lwb() {
    double ll=a[0],rr=max(l-a[n-1],a[n-1]),mid;
    for (int i=0;i<64;i++) {
        mid = ll +(rr-ll)/2.0;
        if (!isValid(mid)) ll=mid;
        else rr=mid;
    }
    return mid;
}
int main() {
    cout.precision(10);
    cin >> n >> l;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    cout << fixed << lwb() << endl;
}
