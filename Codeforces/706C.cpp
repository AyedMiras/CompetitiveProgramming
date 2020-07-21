#include <iostream>
#include <algorithm>
#include <climits>
#define lli long long int
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

lli order [100010][2];
string str[100010];
int c[100010],n;

string rev(const string& s) {
    return string(s.rbegin(),s.rend());
}

int main () {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> c[i];
    for (int i=0;i<n;i++)
        cin >> str[i];
    order[0][1] = c[0];
    for (int i=1;i<n;i++) {
        lli Min1 = INF,Min2 = INF;
        if (str[i] >= str[i-1])
            Min1 = min(Min1,order[i-1][0]);
        if (str[i] >= rev(str[i-1]))
            Min1 = min(Min1,order[i-1][1]);
        if (rev(str[i]) >= str[i-1])
            Min2 = min(Min2,order[i-1][0] + c[i]);
        if (rev(str[i]) >= rev(str[i-1]))
            Min2 = min(Min2,order[i-1][1] + c[i]);
        if (Min1 == INF && Min2 == INF) {
            cout << -1 << endl;
            return 0;
        }
        order[i][0]= Min1;
        order[i][1]= Min2;
    }
    cout << min(order[n-1][0],order[n-1][1]) << endl;
    return 0;
}
