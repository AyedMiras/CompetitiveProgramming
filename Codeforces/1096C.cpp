#include <bits/stdc++.h>
using namespace std;

int T,ang;

int main() {
    cin >> T;
    while(T--){
        cin >> ang;
        for (int i=3;;i++){
            if ( (ang*i%180)==0 && (ang*i)/180<=i-2 ) {
                cout << i << endl;
                break;
            }
        }
    }
}
