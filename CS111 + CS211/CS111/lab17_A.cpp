#include <iostream>
using namespace std;

int removeFirstTwoDigits(int x){
   //if(x < 10)
    //  return x;
   if (x < 1000)
      return x%10;
   return x%10 + removeFirstTwoDigits(x/10);
}

int main(){
  cout << removeFirstTwoDigits(123456) << endl;
}
