#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,l[1000010];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        scanf("%d",l+i);
    if (n==1)
        cout << 1 << endl;
    else {
        int j=n-2;
        int _min = n-1-l[n-1];
        int cnt = 0;
        while (j!=-1){
            if (j>=_min)
                cnt++;
            _min = min(_min,j-l[j]);
            j--;
        }
        cout << n-cnt << endl;
    }
}
