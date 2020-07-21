#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main() {
    cin >> a >> b >> c;
    for (int i=0;i*a<=c;i++) {
        for (int j=0;i*a+j*b<=c;j++) {
            if (i*a + b*j == c) return 0*printf("Yes\n");
        }
    }
    cout << "No" << endl;
}
