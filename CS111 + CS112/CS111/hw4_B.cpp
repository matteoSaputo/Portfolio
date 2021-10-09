#include <iostream>
using namespace std;

int main(){
   int n;
   cout << "Odd Integer: ";
   cin >> n;
   if(n % 2 == 0){
      cout << "Wrong";
      return 0;
   }
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         if(i != n/2 +1){  
            if(j == n/2 +1)
               cout << "*";
            else
               cout << " ";
         }else{
            cout << "*";
         }   
      }
      cout << endl;
   }
   return 0;
}
