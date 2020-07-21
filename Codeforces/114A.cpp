#include <iostream>
#include <cmath>

using namespace std;

int main () {
  long int k,l;
  cin >> k >> l;
  cout << FLT_EPSILON;
  if ( log(l)/log(k) - floor((log(l)/log(k))) ) <= 1e-9 ) cout << "YES" << endl << (log(l)/log(k))  - 1 << endl;
  else cout << "NO" << endl;



  return 0;
}
