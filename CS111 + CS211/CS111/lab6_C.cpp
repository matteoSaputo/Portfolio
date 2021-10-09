#include <iostream>
using namespace std;

int main(){
   int x;
   cout << "Please enter a number: ";
   cin >> x;
   while(x < 100 || x > 999){
      cout << "Bad input. Please enter a number: ";
      cin >> x;
   }
   if(x % (x%10)*(x%10) == 0)
      cout << "Yes, " << (x%10)*(x%10) << " is a factor of " << x << endl;
   else
   	  cout << "No, " << (x%10)*(x%10) << " is not a factor of " << x << endl;
   return 0;
}	  