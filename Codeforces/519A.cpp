#include <iostream>
using namespace std;

int main () {
  char cb[8][8]; //chessboard
  int bw=0,ww=0; //black weight and white weight
  for (int i=0;i<8;i++)
    for (int j=0;j<8;j++){
      cin >> cb[i][j];
      switch (cb[i][j]){
        case 'Q': ww+=9;break;
        case 'R': ww+=5;break;
        case 'B': ww+=3;break;
        case 'N': ww+=3;break;
        case 'P': ww+=1;break;
        case 'q': bw+=9;break;
        case 'r': bw+=5;break;
        case 'b': bw+=3;break;
        case 'n': bw+=3;break;
        case 'p': bw+=1;break;
        default: break;
      }
    }

if (bw > ww) cout << "Black" << endl;
else if (bw < ww) cout << "White" << endl;
else cout << "Draw" << endl;


  return 0;
}
