#include <iostream>
using namespace std;

int main(){
   cout << "Height: ";
   int x;
   cin >> x;
   if(x <= 0){
      cout << "Invalid";
      return 0;
   }
   for(int i = 1; i <= 5; i++){
      for(int j = 0; j < x; j++){
         for(int k = 0; k <= j; k++){
            cout << " "; 
         }
         cout << "*" << endl;
      }
   }
   return 0;
}
          
