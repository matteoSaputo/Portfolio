#include <iostream>
using namespace std;

int max(int x, int y){
   if(x >= y)
      return x;
   return y;
}

int biggerDigit(int x, int y){
   if(x < 10)
      return max(x, y);
   return biggerDigit(x/10, y/10);
}

int main(){
   cout << biggerDigit(54, 37);
   cout << biggerDigit(55, 33);
}
