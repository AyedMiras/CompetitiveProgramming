#include <bits/stdc++.h>
using namespace std;
int n;
string eggs = {"ROIGBVY"};

int main() {
    cin >> n;
    for (int i=0;i<3;i++) cout << eggs[i];
    for (int i=3;i<n;i++) cout << eggs[3+i%4];
    cout << endl;
}

