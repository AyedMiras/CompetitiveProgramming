#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,h,d;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> h,d = max(d,h);
    cout << d << endl;
}
