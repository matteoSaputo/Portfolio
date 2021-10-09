#include <iostream>
using namespace std;

int first2Digit(int x){
   if(x < 100)
      return x;
   return first2Digit(x/10);
}

int main(){
   cout << first2Digit(1234) << endl;
}
