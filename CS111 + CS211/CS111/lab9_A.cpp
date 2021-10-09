#include <iostream>
using namespace std;

int main(){
   int n;
   cout << "positive integer: ";
   cin >> n;
   for(int i = 1; i <= n; i++){
      int x = n;
      for(int j = 1; j <= n; j++){
         if(x > i)
            cout << " ";
         else
            cout << "*";
         x--;
      }
      cout << endl;
   }
   return 0;
}
