#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n;
long long int h,x,c[N];

int main() {
    cin >> n >> x;
    for (int i=0;i<n;i++) cin >> c[i];
    sort(c,c+n);
    for (int i=0;i<n;i++) {
        h+=x*c[i];
        if (x>1) x--;
    }
    cout << h << endl;
}
