#include <bits/stdc++.h>
using namespace std;
const long long int INF = 0x8080808080808080;
vector<long long int> num;
vector<long long int> pr;
int a;

int main() {
    while (1) {
        cin >> a;
        if (cin.eof()) return 0;
        num.clear();pr.clear();
        while(a!= -999999) {
            num.push_back(a);
            cin >> a;
        }
        pr.push_back(num[0]);
        for (int i=1;i<num.size();i++){
            pr.push_back(num[i]*pr[i-1]);
            //cout << pr[i] << endl;
        }
        long long int m = INF;
        for (int i=0;i<num.size();i++) {
            for (int j=i;j<num.size();j++) {
                if (!i) m = max(m,pr[j]);
                else m = max(m,!pr[i]?INF:pr[j]/pr[i-1]);
            }
        }
        cout << m << endl;
    }
}
