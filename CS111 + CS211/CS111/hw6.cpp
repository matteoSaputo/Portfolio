#include <iostream>
using namespace std;

int first2Digit(int x){
   if(x < 100)
      return x;
   return first2Digit(x/10);
}

void doubleOdd(int x){
   if(x < 10){
      if(x%2==0)
         cout << x;
      else
         cout << x*11;
   }
   doubleOdd(x/10);
   cout << endl;
}

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

int containsEven(int x){
	if(x < 10)
	   return x % 2 == 0;
	return containsEven(x/10);
}

int main(){
  int x = 123456, y = 444444;
  cout << "Doubled odd ";
  doubleOdd(x); //output: 112334556 
  cout << endl;
  doubleOdd(y); //output: 444444 
  cout << endl;
  int ans = biggerDigit(x, y);
  cout << ans << endl; //output: 444456
  doubleOdd(ans); //output: 4444556
  cout << first2Digit(x) << endl; //output: 12
  cout << first2Digit(321) << endl; //output: 32
  if (containsEven(1357))
     cout << "1357 contains even?" << endl;
  if (containsEven(12357))
     cout << "12357 contains even!" << endl;
  cout << endl;
  return 0;
}