#include <iostream>

using namespace std;
int n;
int cnt;
int main() {
    cin >> n;
    if (n%3 ==0)
        cout << 2*(n/3)<<endl;
    else if (n%3 == 1)
        cout << 2*((n-1)/3) +1 << endl;
    else
        cout << 2*((n+1)/3)-1 << endl;


}
