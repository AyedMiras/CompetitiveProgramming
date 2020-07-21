#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n,math[5005],prog[5005],sport[5005];
  int cmp1=0,cmp2=0,cmp3=0;
  int temp;
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> temp;
    switch(temp){
      case 1:prog[cmp1]=i+1;cmp1++;break;
      case 2:math[cmp2]=i+1;cmp2++;break;
      case 3:sport[cmp3]=i+1;cmp3++;break;
    }
  }
  if (cmp1 && cmp2 && cmp3) {
    int Min = min(cmp1,min(cmp2,cmp3));
    cout << Min << endl;
    for (int i=0;i<Min;i++) {
      cout << prog[i] << " " << math[i] << " " << sport[i] << endl;
    }
  }
  else {
    cout << 0 << endl;
  }


  return 0;
}
