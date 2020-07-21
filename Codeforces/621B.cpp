#include <iostream>
using namespace std;
int n;
long long int res;
long long int sumDiag[2000];
long long int diffDiag[2000];

int main() {
    cin >> n;
    for (int k=0;k<n;k++) {
        int i,j;
        cin >> i >> j;
        sumDiag[i+j-2]++;
        diffDiag[1000-i+j]++;
    }
    for (int i=0;i<2000;i++) {
        res +=(sumDiag[i]*(sumDiag[i]-1))/2;
        res += (diffDiag[i]*(diffDiag[i]-1))/2;
    }
    cout << res << endl;
}
