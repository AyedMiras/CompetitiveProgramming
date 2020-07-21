#include <bits/stdc++.h>
using namespace std;
int n,ans,h;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> ans;
        if (ans)
            h=1;
    }
    if (h)
        cout << "HARD";
    else
        cout << "EASY";
    cout << endl;
}
