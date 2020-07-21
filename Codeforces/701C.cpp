#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string s;
vector<int> low_alpha[30];
vector<int> upper_alpha[30];

bool _search(vector<int> v, int i, int j) {
    vector<int>::iterator l=v.begin(),r=v.end();
    while (r>l){
        const vector<int>::iterator mid = l + std::distance(l,r)/2;
        if (i<=*mid && *mid<=j){
            return true;
        }
        else if (*mid <i)
            l = mid+1;
        else
            r=mid;
    }
    return false;
}

int main() {
    cin >> n >> s;
    for (int i=0;i<n;i++) {
        if (s[i] >='a' && s[i] <='z')
            low_alpha[s[i]-'a'].push_back(i);
        else
            upper_alpha[s[i]-'A'].push_back(i);
    }
    int i=0, j=n-1;
    while(1) {
        if (s[i] >='a' && s[i] <= 'z' && _search(low_alpha[s[i]-'a'], i+1 ,j) )
            i++;
        else if (s[i] >='A' && s[i] <= 'Z' && _search(upper_alpha[s[i]-'A'], i+1 ,j) )
            i++;
        else
            break;
        if (i==n-1)
            break;
    }
    while(j>i) {
        if (s[j] >='a' && s[j] <= 'z' && _search(low_alpha[s[j]-'a'], i ,j-1) )
            j--;
        else if (s[j] >='A' && s[j] <= 'Z' && _search(upper_alpha[s[j]-'A'], i ,j-1) )
            j--;
        else
            break;
    }
    cout << j-i+1 << endl;
}
