#include <iostream>
using namespace std;

int main(){
   int a[5] = {1,2,3,4,5};	//array of 5 ints
   int b[2][3] = {{1,2,3},	//2d array with 2 rows and 3 columns
   				  {3,2,1}};
   cout << a[a[0]];			// prints 2
   cout << b[b[0][0]][a[1]];  // prints 1
   return 0;
}
