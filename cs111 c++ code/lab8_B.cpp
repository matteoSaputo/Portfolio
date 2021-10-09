#include <iostream> 
using namespace std; 

int main(){
   int x;
   cout << "Positive integer: ";
   cin >> x;
   while(x <= 0){
      cout << "Positive integer: ";
      cin >> x;
   }
   while(x > 0){
      cout << x%10;
      x /= 10;
   }
   return 0;
}
