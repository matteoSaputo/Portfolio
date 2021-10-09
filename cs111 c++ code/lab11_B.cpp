#include <iostream>
#include <cmath>
using namespace std;

int main(){
   for(int i = 1000; i <= 10000; i++){
      if(sqrt(i) - round(sqrt(i)) == 0) 
         cout << i << " ";
   }
   return 0;
}
