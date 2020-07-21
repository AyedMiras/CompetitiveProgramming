#include <iostream>
using namespace std;
long long int l,r;

int main() {
    cin >> l >> r;
    long long int pow2 = 2LL;
    long long int pow3;
    long long int cmp = 0;
    if (l==1)
        cmp++,l++;
    while(pow2 <= r) {
        pow3 = pow2;
        while(pow3<=r) {
            if (pow3 >= l)
                cmp++;
            pow3 *=3;
        }
        pow2*=2;
    }
    pow3 = 1LL;
    while(pow3<l)
        pow3*=3;
    while(pow3<=r)
        cmp++,pow3*=3;
    cout << cmp << endl;
}
