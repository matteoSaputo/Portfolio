#include <iostream>
using namespace std;

int main(){
   cout << "Enter an integer: ";
   int x, sum = 0;
   cin >> x;
   for(int i = 0; i <= x*2; i++){
      if(i % 2 != 0){
         cout << i;
         if(i - 2 <= x*2 - 2)
            cout<<"+"; 
         sum += i;
      }
   }
   cout << "=" << sum;
   return 0;
}
