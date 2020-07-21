#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
int n,m;
long long int cnt,a[N],b[N];

// O(1) solution

int main() {
    cin >> n >> m;
    a[0] = n/5;
    b[0] = m/5;
    for (int i=1;i<5;i++) {
        a[i] = n/5 + (n%5 >=i);
        b[i] = m/5 + (m%5 >=i);
    }
    for (int i=1;i<5;i++)
        cnt+= a[i]*b[(5-i)%5];
    cout << cnt << endl;
}
