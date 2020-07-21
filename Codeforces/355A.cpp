#include <bits/stdc++.h>
using namespace std;
int k,d;

int main() {
    cin >> k >> d;
    if (!d && k>1) return 0*printf("No solution\n");
    cout << d;
    for (int i=1;i<k;i++)
        cout << 0;
    cout << endl;
}
