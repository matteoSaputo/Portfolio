#include <iostream>
using namespace std;

void doubleOdd(int x){
   if(x < 10){
      if(x%2==0)
         cout << x;
      else
         cout << x*11;
   }
   doubleOdd(x/10);
   cout << endl;
}

int main(){
   doubleOdd(1);
   doubleOdd(2);
   doubleOdd(112);
}
