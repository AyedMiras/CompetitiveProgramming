#include <bits/stdc++.h>
using namespace std;
int T;
double a,b;

int main() {
    cin >> T;
    while(T--) {
        cin >> a >> b;
        if(!b) {
            cout << 1 << endl;
            continue;
        }
        if (!a) {
            cout << 0.5 << endl;
            continue;
        }
        cout << setprecision(12) << (a*min(a/4,b) - 2*min(a/4,b)*min(a/4,b) + a*b)/(2*a*b) << endl;
    }
}
