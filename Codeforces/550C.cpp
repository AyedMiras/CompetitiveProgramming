#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int num(int i,int j, int k) {
    return (s[i]-'0')*100 + (s[j]-'0')*10 + s[k]-'0';
}

int num(int i, int j) {
    return (s[i]-'0')*10 + s[j]-'0';
}

int num(int i) {
    return s[i]-'0';
}


int main() {
    cin >> s;
    n = s.length();
    for (int i=0;i<n;i++) {
        if (num(i)%8==0) return 0*printf("YES\n%d",num(i));
    }

    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (num(i,j)%8==0) return 0*printf("YES\n%d",num(i,j));
        }
    }

    for (int i=0;i<n-2;i++) {
        for (int j=i+1;j<n-1;j++) {
            for (int k=j+1;k<n;k++) {
                if (num(i,j,k)%8==0) return 0*printf("YES\n%d",num(i,j,k));
            }
        }
    }

    cout << "NO" << endl;
}
