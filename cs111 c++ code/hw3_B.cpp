#include <iostream>
using namespace std;

int main(){
   cout << "Positive integer: ";
   int x;
   cin >> x;
   if(x <= 0){
      cout << "Wrong";
      return 0;
   }
   int count = 0;
   while(x > 0){
      x /= 10;
      count++;
   }
   cout << endl << count;
   return 0;
}
