#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N];
bool flag;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for (int i=0;i<n-2;i++) {
        if (a[i]+a[i+1]>a[i+2]) {
            flag = true;
            break;
        }
    }
    cout << (flag?"YES":"NO") << endl;
}
