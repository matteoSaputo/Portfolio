#include <iostream>
using namspace std;

int main(){
   cout << "Enter a number less than 20: ";
   int x, count;
   cin << x;
   cout << "Two digit numbers that's a multiple of " << x << " but not 3: ";
   count = 1;
   while(count < x){
      if(count % 2 == 0 && count % 3 != 0){
         cout << count << ", ";
      count ++;
   }
   return 0;
}
