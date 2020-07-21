#include <bits/stdc++.h>
using namespace std;
const int N=20;
char a[N];
string fact[10];
string res;

void init() {
    fact[2]="2";
    fact[3]="3";
    fact[4]="322";
    fact[5]="5";
    fact[6]="53";
    fact[7]="7";
    fact[8]="7222";
    fact[9]="7332";
}

int main() {
    init();
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++)
        res+=fact[a[i]-'0'];
    sort(res.rbegin(),res.rend());
    cout << res << endl;

}
