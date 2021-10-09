#include <iostream>
using namespace std;

void oddToStar(int x){
   if(x < 10){
      if(x % 2 == 0)
         cout << x;
      else
         cout << "*";
   }
   cout << oddToStar(x/10); 
   return;  
}

int main(){
   oddToStar(127143);
   return 0;
}