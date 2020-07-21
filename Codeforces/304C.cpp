#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    if (!(n&1)) return 0*printf("-1\n");

    for (int i=0;i<n;i++) cout << i << " \n"[i==n-1];
    for (int i=0;i<n;i++) cout << i << " \n"[i==n-1];
    for (int i=0;i<n;i++) cout << (2*i)%n << " \n"[i==n-1];
}
