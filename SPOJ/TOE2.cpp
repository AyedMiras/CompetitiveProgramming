#include <bits/stdc++.h>
using namespace std;
string s;
int xcnt,ocnt;
char grid[3][3];
bool flag,xwin,owin;

int main() {
    while(1) {
        cin >> s;
        if (s=="end") return 0;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                grid[i][j] = s[3*i+j];
        xcnt=0,ocnt=0,flag=true,xwin=owin=false;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if (grid[i][j]=='X') xcnt++;
                else if (grid[i][j]=='O') ocnt++;
        //Check Rows
        for (int i=0;i<3;i++) {
            if (grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]) {
                if (grid[i][0]=='X')
                    xwin = true;
                else if (grid[i][0]=='O')
                    owin = true;
            }
        }
        //Check Columns
        for (int i=0;i<3;i++) {
            if (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]) {
                if (grid[0][i]=='X')
                    xwin = true;
                else if (grid[0][i]=='O')
                    owin = true;
            }
        }
        //Check first Diagonal
        if (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]) {
            if (grid[0][0]=='X')
                xwin = true;
            else if (grid[0][0]=='O')
                owin = true;
        }
        //Check second Diagonal
        if (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]) {
            if (grid[0][2]=='X')
                xwin = true;
            else if (grid[0][2]=='O')
                owin = true;
        }
        //Result
        if (xwin && xcnt!=ocnt+1)
            flag = false;
        if (owin && ocnt!=xcnt)
            flag = false;
        if (xwin && owin)
            flag = false;
        if (!xwin && !owin && !(xcnt==5 && ocnt==4))
            flag = false;
        cout << (flag?"valid":"invalid") << endl;
    }
}

