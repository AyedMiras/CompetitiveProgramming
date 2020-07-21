#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
vector<char> name(N);

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        name[i] = 'o';
    int f0 = 1;
    int f1 = 2;
    name[0]='O',name[1]='O';
    while(f1<n){
        f1 = f0 + f1;
        f0 = f1 - f0;
        name[f1  -1]= 'O';
    }
    for (int i=0;i<n;i++)
        cout << name[i];
    cout << endl;
}
