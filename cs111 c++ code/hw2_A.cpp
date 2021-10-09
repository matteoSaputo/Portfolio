#include <iostream>
using namespace std;

int main(){
   int x, y;
   cout << "Enter a positive integer: ";
   cin >> x;
   cout << "Enter a positive integer: ";
   cin >> y;
   if((x < 0 || x > 20) || (y < 0 || y > 20)){
      cout << "Must be positive and less than 20. You failed!";
      return 0;
   }
   if(x < y && y < 5)
      cout << "Answer: " << x * (y+5);
   else if( y < x && x < 5)
      cout << "Answer: " << (x+y) % 5;
   else
      cout << "Answer: " << x/y;
   return 0;
} 
