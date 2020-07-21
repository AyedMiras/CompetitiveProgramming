#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main() {
    cin >> n;
    if (n<=2) return 0*printf("1\n1\n");
    if (n==3) return 0*printf("2\n1 3\n");
    cout << n << endl;
    for (int i=2;i<=n;i+=2)
        cout << i << " ";
    for (int i=1;i<=n;i+=2)
        cout << i << " \n"[i>=n-1];
}
