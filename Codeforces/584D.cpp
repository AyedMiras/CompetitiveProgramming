#include <iostream>
#include <cmath>
using namespace std;

int N;

bool isPrime(const int& N) {
    if (N == 2 ||N ==3)
        return true;
    if (N%2==0 || N%3==0)
        return false;
    for (int i=5;i<=sqrt(N);i+=6)
        if (N%i==0 || N%(i+2)==0)
            return false;
    return true;

}
int main () {
    cin >> N;
    if (!(N&1)){
            cout << 2 << endl;
            cout << 2 << " " << N-2 << endl;
            return 0;
    }
    if (isPrime(N)) {
        cout << 1 << endl;
        cout << N << endl;
        return 0;
    }
    if (isPrime(N-2)) {
        cout << 2 << endl;
        cout << 2 << " " << N-2 << endl;
        return 0;
    }

    int i = N-4;
    while (!isPrime(i))
        i-=2;
    cout << 3 << endl;
    cout << i << " ";
    i = N-i;
    if (isPrime(2) && isPrime(i-2)) {
        cout << 2 << " " << i-2 << endl;
        return 0;
    }
    for (int j=3;j<= (i>>1);j+=2) {
        if (isPrime(j) && isPrime(i-j)) {
            cout << j << " " << i-j << endl;
            return 0;
        }
    }
}
