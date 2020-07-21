#include <bits/stdc++.h>
using namespace std;
long long int b[3],cnt;

int main() {
    cin >> b[0] >> b[1] >> b[2];
    sort(b,b+3);
    if (2*(b[0]+b[1])<=b[2]) cout << b[0]+b[1] << endl;
    else cout << (b[0]+b[1]+b[2])/3 << endl;
    // Or just cout << min( (b[0]+b[1]+b[2]) /3, b[0]+b[1]) << endl;
}
