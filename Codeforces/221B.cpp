#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int x;
vector<int> divs;

void _fill_div(int x) {
    for (int i=1;i*i<=x;i++) {
        if (!(x%i)) {
            if (i*i==x)
                divs.push_back(i);
            else
                divs.push_back(i),divs.push_back(x/i);
        }
    }
}
bool common_digit(int x, int y) {
    char s1[11],s2[11];
    sprintf(s1,"%d",x);
    sprintf(s2,"%d",y);
    bool d[10];
    memset(d,0,10*sizeof(bool));
    for (int i=0;s1[i];i++)
        d[s1[i]-'0']=true;
    for (int i=0;s2[i];i++)
        if (d[s2[i]-'0'])
            return true;
    return false;
}
int main() {
    cin >> x;
    int cmp = 0;
    _fill_div(x);
    for (int i=0;i<divs.size();i++) {
        if (common_digit(x,divs[i]))
            cmp++;
    }
    cout << cmp << endl;
}
