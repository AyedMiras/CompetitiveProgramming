#include <bits/stdc++.h>
using namespace std;
int n;
string s;
deque<char> d;

int main() {
    cin >> n >> s;
    while(n) {
        if (n&1) d.push_back(s[0]);
        else d.push_front(s[0]);
        s.erase(0,1);
        n--;
    }
    while(!d.empty())
        cout << d.front(),d.pop_front();
    cout << endl;
}
