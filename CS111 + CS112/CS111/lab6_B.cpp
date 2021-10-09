#include <iostream>
using namespace std;

int main(){
   int grade;
   cout << "Enter a grade out of 100: ";
   cin >> grade;
   while(grade < 0 || grade > 100){
      cout << "Not a valid grade! Try again: ";
      cin >> grade;
   }
   if(grade > 90)
      cout << "A";
   else if(grade > 80)
      cout << "B";
   else if(grade > 70)
      cout << "C";
   else if(grade > 60)
      cout << "D";
   else 
      cout << "F";
   return 0;
}
