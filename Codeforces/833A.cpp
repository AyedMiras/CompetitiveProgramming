#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a,b;
bool sqr[150];

void init() {
    for (int i=2;i*i<=N;i++)
        sqr[i*i]=1;
}
int main() {
    cin >> n >> a >> b;
    while(n--) {
        for (int i=2;i*i<=max(a,b);) {
            if (a%i==0 && b%(i*i)==0) a/=i,b/=i*i;
            else if (b%i==0  && a%(i*i)==0) b/=i,a/=i*i;
            else i++;
        }
        if (a==b && a==1) cout << "Yes" << endl;
    }
}
