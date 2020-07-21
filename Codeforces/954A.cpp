#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i=0;i<s.length()-1;) {
        if (s[i]!=s[i+1])
            n--,i++;
        i++;
    }
    cout << n << endl;
}
