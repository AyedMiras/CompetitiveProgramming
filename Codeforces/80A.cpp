#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,m;
bool sieve[50];
map<int,int> nxt;

void eras() {
    int pred = -1;
    for (int i=2;i<N;i++) {
        if (!sieve[i]) {
            for (int j=2;j*i<N;j++)
                sieve[i*j]=1;
            nxt[pred]=i;
            pred=i;
        }
    }
}

int main() {
    eras();
    cin >> n >> m;
    cout << (nxt[n]==m?"YES":"NO");
}
