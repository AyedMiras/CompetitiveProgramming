#include <iostream>
using namespace std;
int n,m;

int main() {
    cin >> n >> m;
    m%= (n*(n+1) )/2;
    for (int i=1;i<=n;i++) {
        if (m<i)
            break;
        m-=i;
    }
    cout << m << endl;
}
