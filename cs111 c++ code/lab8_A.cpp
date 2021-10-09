#include <iostream>
using namespace std; 
int main(){
   int x = 15;
   x -= 5;
   cout << x << endl; //
   x++;
   while (x > 5){ //Output from entire loop: 96
      if (x % 3 == 0)
         cout << x;
      x--;
   }
   cout << endl; 
   return 0;
}
