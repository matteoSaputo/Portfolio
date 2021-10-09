#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
   srand(time(0));
   int x;
   for(int i = 1; i <= 4; i++){
      for(int j = 1; j <= 5; j++){
         x = rand() % 99 + 10;
         cout << x << " ";
      }
      cout << endl;
   }
   cout << sqrt(x);
   return 0;
}
  
