#include <iostream>
using namespace std;

void fun(int a[], int c, int x){
   if (c <= x){
      cout << x;
      return;
   }
   a[x] = c;
   cout << c;
}
int main(){
   int a[5] = {1,2,3,4,5};
   int b[2][3] = {{1,2,3},{3,2,1}};
   cout << a[a[3] / 2];
   for (int r = 0; r < 2; r++) for (int c = 2; c >= 0; c--) cout << b[r][c];
   cout << endl;
   fun(a, 1, 5);
   fun(a, 5, 1);
   for (int i = 0; i < 5; i++) cout << a[i] << " "; cout << endl;
   return 0;
}

// output: 3321123
//		   551 5 3 4 5