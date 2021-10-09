#include <iostream>
using namespace std;

int main(){
   int a, b;
   cout << "Enter two integers: ";
   cin >> a;
   cin >> b;
   for(int i = 1; i <= a+b; i++){
      for(int j = 1; j <= a*b; j++){
         cout << "X";
         if(j % b == 0)
            cout << "|";
      }
      cout << endl;
   }
   return 0;
}
