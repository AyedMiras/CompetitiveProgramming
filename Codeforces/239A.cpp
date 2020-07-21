#include <iostream>
using namespace std;

int main () {
  int y,k,n;
  int mul[100010];
  bool first = true;
  cin >> y >> k >> n;
  for (int i=1;i<= (n/k) ;i++) {
    mul[i] = k*i;
  }
  for (int i=1;i<=n/k;i++) {
    if (mul[i]-y >=1 && mul[i]-y <=n) {
      if (first) {
        cout << mul[i] - y;
        first = false;
      }
      else cout << " " << mul[i] - y;
    }
  }
  if (first) cout << -1 << endl;
  else cout << endl;



  return 0;
}
