#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    if (!n) cout << 1 << endl;
    else if (n%4 == 1) cout << 8 << endl;
    else if (n%4 == 2) cout << 4 << endl;
    else if (n%4 == 3) cout << 2 << endl;
    else cout << 6 << endl;
}
