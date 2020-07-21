#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
  if (n&1) {
    for (int i=3;i<=sqrt(n);i+=2)
      if (!(n%i)) return false;
    return true;
  }
  else
    return false;
}

int main() {
  int n;
  cin >> n;
  int mid= n/2;
  while (isPrime(mid) || isPrime(n-mid) ) mid--;
  cout << mid <<" "<< n - mid << endl;


  return 0;
}
