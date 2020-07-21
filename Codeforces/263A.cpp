#include <iostream>

using namespace std;

int main () {
  int x,temp;
  for (int i=0;i<25;i++) {
    cin >> x;
    if (x) temp = i;
  }
  cout << abs(temp/5 -2) + abs(temp%5 - 2);


  return 0;
}
