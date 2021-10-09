#include <iostream>
using namespace std;

int main(){
   int num;
   cout << "Please enter a positive integer: ";
   cin >> num;
   if(num < 10){
      cout << "Not valid, good-bye!";
      return 0;
   }
   cout << num % 10 << (num/10) % 10;
   return 0;
}
