#include <bits/stdc++.h>
using namespace std;
int n;
char bus[1010][5];
bool flag;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<5;j++)
            cin >> bus[i][j];
        if (!flag && bus[i][0] == bus[i][1] && bus[i][0] =='O') {
            bus[i][0]=bus[i][1]='+';
            flag = true;
        }
        if (!flag && bus[i][3]==bus[i][4] && bus[i][3] == 'O') {
            bus[i][3]=bus[i][4]='+';
            flag = true;
        }
    }
    if (!flag) return 0*printf("NO\n");
    cout << "YES" << endl;
    for (int i=0;i<n;i++) {
        for (int j=0;j<5;j++) {
            cout << bus[i][j];
        }
        cout << endl;
    }
}
