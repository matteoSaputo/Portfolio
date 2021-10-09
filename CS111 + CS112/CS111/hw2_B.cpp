#include <iostream>
using namespace std;

int main(){
   int month;
   cout << "Enter your birth month (1 - 12): ";
   cin >> month;
   while(month < 1 || month > 12){
      cout << "Please enter a valid month (1 - 12): ";
      cin >> month;
   }
   if(month == 9){
      cout << "Happy Birthday!!! Your birthday is this month!";
      return 0;
   }else if(month < 9){
      cout << "Your birthday passed for this year, next one is in " << month + 3 << " month(s)";
      return 0;
   }else if(month > 9){
      cout << "Your birthday is in " << month - 9 << " month(s)";
   }
   return 0;
}
