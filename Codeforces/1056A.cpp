#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,r,cnt[N];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> r;
        for (int j=0;j<r;j++) {
            int tmp;
            cin >> tmp;
            cnt[tmp]++;
        }
    }
    int flag=0;
    for (int i=0;i<N;i++) {
        if (cnt[i]==n) {
            if (!flag) {
                cout << i;
                flag=1;
            }
            else
                cout << " " << i;
        }
    }
    cout << endl;
}
