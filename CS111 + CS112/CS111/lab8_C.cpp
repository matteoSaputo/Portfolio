#include <iostream>
using namespace std;

int main(){
   int x;
   cout << "Enter a positive integer that is greater than 20: ";
   cin >> x;
   if(x <= 20){
     cout << "Wrong!";
     return 0;
   }
   for(int i = 1; i <= x; i++){
      cout << "*";
      if(i % 5 == 0)
         cout << " ";
   }
   return 0;
}
