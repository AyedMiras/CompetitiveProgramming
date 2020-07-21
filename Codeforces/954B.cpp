#include <iostream>
using namespace std;

int n;
string s;

bool sym(int n){
    for (int i=0;i<n/2;i++) {
        if (s[i]!=s[n/2+i])
            return false;
    }
    return true;
}
int main() {
    cin >> n >> s;
    bool flag = true;
    int op = 0;
    while(n) {
        if (n&1)
            n--;
        else if (flag && sym(n))
            n=n/2,flag=false;
        else
            n--;
        op++;

    }
    cout << op << endl;
}
