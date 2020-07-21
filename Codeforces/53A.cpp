#include <bits/stdc++.h>
using namespace std;
const int N=110;
string hist[N],input;
vector<string> prefixed;
int n;

bool comp(string s1, string s2) {
    return strcmp(s1.c_str(),s2.c_str()) < 0;
}

bool isPref(string s1, string s2) {
    if (s1.size()<s2.size())
        return false;
    for (int i=0;i<s2.size();i++)
        if (s1[i]!=s2[i])
            return false;
    return true;
}

int main() {
    cin >> input >> n;
    for (int i=0;i<n;i++) {
        cin >> hist[i];
        if (isPref(hist[i],input))
            prefixed.push_back(hist[i]);
    }
    //for (int i=0;i<prefixed.size();i++)
    //    cout << prefixed[i] << " \n"[i==prefixed.size()-1];
    if (!prefixed.empty()) {
        sort(prefixed.begin(),prefixed.end(),comp);
        cout << prefixed[0] << endl;
    }
    else
        cout << input << endl;
}
