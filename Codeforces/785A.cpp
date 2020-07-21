#include <bits/stdc++.h>
using namespace std;
int n,cnt;
map<string,int> faces;
string s;

void init() {
    faces["Tetrahedron"] = 4;
    faces["Cube"] = 6;
    faces["Octahedron"] = 8;
    faces["Dodecahedron"] = 12;
    faces["Icosahedron"] = 20;

}
int main() {
    init();
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s;
        cnt+=faces[s];
    }
    cout << cnt << endl;
}
