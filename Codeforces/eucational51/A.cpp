#include <bits/stdc++.h>
using namespace std;
int T,cnt[3];
string s;

bool isLower(char c) {
    return c>='a' && c<='z';
}

bool isUpper(char c) {
    return c>='A' && c<='Z';
}

bool isDig(char c) {
    return c>='0' && c<='9';
}

int main() {
    cin >> T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        cin >> s;
        for (int i=0;s[i];i++) {
            if (isLower(s[i]))
                cnt[0]++;
            if (isUpper(s[i]))
                cnt[1]++;
            if (isDig(s[i]))
                cnt[2]++;
        }
        //cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
        bool flag=0;
        if (cnt[0] && cnt[1] && cnt[2])
            cout << s << endl;
        else if (cnt[0]>1 && (cnt[1]||cnt[2])) {
            for (int i=0;i<s[i];i++) {
                if (!flag && isLower(s[i]))
                    cout << (cnt[1]?'0':'A'),flag=1;
                else
                    cout << s[i];
            }
            cout << endl;
        }
        else if (cnt[0]>2 && !cnt[1] && !cnt[2]) {
            cout << "A0" <<  s.substr(2) << endl;
        }
        else if (cnt[1]>1 && (cnt[0]||cnt[2])) {
            for (int i=0;i<s[i];i++) {
                if (!flag && isUpper(s[i]))
                    cout << (cnt[0]?'0':'a'),flag=1;
                else
                    cout << s[i];
            }
            cout << endl;
        }
        else if (cnt[1]>2 && !cnt[0] && !cnt[2]) {
            cout << "a0" <<  s.substr(2) << endl;
        }
        else if (cnt[2]>1 && (cnt[0]||cnt[1]) ) {
            for (int i=0;i<s[i];i++) {
                if (!flag && isDig(s[i]))
                    cout << (cnt[0]?'A':'a'),flag=1;
                else
                    cout << s[i];
            }
            cout << endl;
        }
        else if (cnt[2]>2 && !cnt[0] && !cnt[1]) {
            cout << "aA" << s.substr(2) << endl;
        }
    }
}
