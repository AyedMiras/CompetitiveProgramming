#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,a[N],b[N],st,en;
bool flag;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i],b[i]=a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++) {
        if (a[i]!=b[i]) {
            st = i;
            break;
        }
    }
    for (int i=n-1;i>=0;i--) {
        if (a[i]!=b[i]) {
            en = i;
            break;
        }
    }
    for (int i=st,j=en;i<=en;i++,j--) {
        if (a[i]!=b[j]) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl << ++st << " " << ++en << endl;
}
