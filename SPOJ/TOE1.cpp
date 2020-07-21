#include <bits/stdc++.h>
using namespace std;
int T,xcnt,ocnt;
char grid[3][3];
bool flag;

int main() {
    cin >> T;
    while(T--) {
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                cin >> grid[i][j];
        xcnt=0,ocnt=0,flag=true;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if (grid[i][j]=='X') xcnt++;
                else if (grid[i][j]=='O') ocnt++;
        //X count vs O count
        if (xcnt!=ocnt && xcnt !=ocnt+1)
            flag = false;
        //Check Rows
        for (int i=0;i<3;i++) {
            if (grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]) {
                if (grid[i][0]=='X' && xcnt==ocnt)
                    flag = false;
                else if (grid[i][0]=='O' && xcnt>ocnt)
                    flag = false;
            }
        }
        //Check Columns
        for (int i=0;i<3;i++) {
            if (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]) {
                if (grid[0][i]=='X' && xcnt==ocnt)
                    flag = false;
                else if (grid[0][i]=='O' && xcnt>ocnt)
                    flag = false;
            }
        }
        //Check first Diagonal
        if (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]) {
            if (grid[0][0]=='X' && xcnt==ocnt)
                flag = false;
            else if (grid[0][0]=='O' && xcnt>ocnt)
                flag = false;
        }
        //Check second Diagonal
        if (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]) {
            if (grid[0][2]=='X' && xcnt==ocnt)
                flag = false;
            else if (grid[0][2]=='O' && xcnt>ocnt)
                flag = false;
        }
        //Result
        cout << (flag?"yes":"no") << endl;
    }
}
