#include <iostream>

using namespace std;
bool mul[100010];

int main () {
  int k,l,m,n,d;
  cin >> k >> l >> m >> n >> d;
  for (int i = 1; k*i<=d;i++)
    mul[k*i] = true;
  for (int i = 1; l*i<=d;i++)
    mul[l*i] = true;
  for (int i = 1; m*i<=d;i++)
    mul[m*i] = true;
  for (int i = 1; n*i<=d;i++)
    mul[n*i] = true;
  int cmp = 0;
  for (int i=1;i<=d;i++)
    if (mul[i]) cmp++;
  cout << cmp << endl;


  return 0;
}
