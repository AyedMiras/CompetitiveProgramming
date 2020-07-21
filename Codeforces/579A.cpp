#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  int cmp = 0;
  while(x) {
    cmp+= x&1;
    x = x/2;
  }
  cout << cmp;

  return 0;
}
