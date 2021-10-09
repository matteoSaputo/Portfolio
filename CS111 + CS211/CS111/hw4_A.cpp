#include <iostream>
using namespace std;

int main(){
   int n;
   cout << "Positive integer: ";
   cin >> n;
   for(int i = 0; i < n*5; i++){
      cout << "*"; 
   }
   cout << endl;
   for(int i = 3; i >= 1; i--){
      for(int j = 1; j <= i; j++){
         cout << " ";
      }
      for(int j = 1; j <= n; j++){
         cout << "*    ";
      }
      cout << endl;
   }      
   for(int i = 0; i < n*5; i++){
      cout << "*";
   }
   return 0;
}
