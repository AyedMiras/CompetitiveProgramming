#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
  int n,arg1,arg2,cmp=1,Max=1; //longest consecutive increasing subarray
  scanf("%d",&n);
  scanf("%d",&arg1);
  for (int i=1;i<n;i++) {
    scanf("%d",&arg2);
    if (arg2>arg1) cmp++;
    else Max=max(Max,cmp), cmp =1;
    arg1=arg2;
  }
  Max=max(Max,cmp);
  printf("%d",Max);




  return 0;
}
