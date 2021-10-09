#include <iostream>
using namespace std;

int main(){
   cout <<"Enter an integer greater than 20: ";
   int x, f;
   cin >> x;
   while(x <= 20){
      cout << "Enter an integrer greater than 20: ";
      cin >> x;
   }
   int y = x;
   for(int i = x; i >= 2; i--){
      if(x % i == 0 && x / i > y)
          f = x/i;
   }
   cout << "Greatest factor: " << f;
   return 0;
}
          
