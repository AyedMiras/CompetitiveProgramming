#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
bool sieve[N];
vector<int> res;

void eras() {
    for (int i=2;i<N;i++) {
        if (!sieve[i])
            for (int j=2;i*j<N;j++)
                sieve[i*j]=1;
    }
}

int main() {
    eras();
    cin >> n;
    if (n==1) return 0*printf("0\n");
    for (int i=2;i<=n;i++) {
        if (!sieve[i]) {
            for (int p=i;p<=n;p=p*i) {
                res.push_back(p);
            }
        }
    }
    cout << res.size() << endl;
    for (int i=0;i<res.size();i++)
        cout << res[i] << " \n"[i==res.size()-1];
}
