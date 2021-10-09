#include <iostream>
using namespace std;

int main(){
   cout << "Height: ";
   int x;
   cin >> x;
   if(x <= 0 || x % 2 == 0){
      cout << "Invalid";
      return 0;
   }
   for(int i = 1; i <= x; i++){
      for(int j = 1; j <= x; j++){
         if(i == x/2 + 1){
            if(j == x/2 + 1)
               cout << "+";
            else
               cout << " ";
         }else{
            if(j < x/2 + 1){
               if(j == i)
                  cout << "*";
               else if(j == x - i)
                  cout << "o";
               else
                  cout << " ";
            }else{
               if(j == x - 1)
                  cout << "*";
               else if(j == i)
                  cout << "o";
               else
                  cout << " ";
            }
         }  
      }
      cout << endl;
   }
   return 0;
}
