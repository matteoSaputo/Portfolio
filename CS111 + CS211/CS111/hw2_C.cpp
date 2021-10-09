#include <iostream>
using namespace std;

int main(){
   int num, chances = 5;
   cout << "Please enter a 2 digit positive number: ";
   cin >> num;
   while(num < 10 || num > 100){
      if(chances == 1){
         cout << "Bad input! Bye, idiot!";
         return 0;
      }    
      cout << "Bad input! Please enter a positive integer: ";
      cin >> num;
      chances--;
   }
   if(num / 10 % 2 == 0){
      cout << "First digit is even";
   }else{
      cout << "First digit is odd";
   }
   return 0;
} 
