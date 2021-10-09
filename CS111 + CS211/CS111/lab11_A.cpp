#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int main(){
   srand(time(0));
   int sum = 0;
   while(sum <= 10){
      for(int i = 0; i < 3; i++){
	 int x = rand()%6+1;
         cout << x << " ";
         sum += x;
      }
      cout << endl;
   }
   return 0;
}
