#include <bits/stdc++.h>
using namespace std;
string x;
deque<char> dq;
int cnt;
bool flag;

int main() {
    cin >> x;
    for (int i=0;x[i];i++)
        dq.push_back(x[i]);
    while(dq.size()!=1) {
        if (dq.back()=='0') {
            dq.pop_back();
            cnt++;
            continue;
        }
        flag = false;
        for (deque<char>::reverse_iterator it = dq.rbegin();it!=dq.rend();++it) {
            if (*it == '0') {
                *it = '1';
                flag = true;
                break;
            }
            *it = '0';
        }
        if (!flag)
            dq.push_front('1');
        cnt++;
    }
    cout << cnt << endl;
}
