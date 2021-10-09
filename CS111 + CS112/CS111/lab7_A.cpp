#include <iostream>
using namespace std;

int main(){
   int x, first;
   cout << "Please enter a positive number: ";
   cin >> x;
   if(x <= 0){
      cout << "Bye!";
      return 0;
   }
   for(int i = 1; i <= x; i++){
      if(x % i == 0)
         cout << i << ", ";
   }
   first = x;
   while(first >= 10){
      first /= 10; 
   }
   cout << "First digit of " << x << " is " << first;
   return 0;
}
