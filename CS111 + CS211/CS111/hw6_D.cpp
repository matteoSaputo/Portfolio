#include <iostream>
using namespace std;

int containsEven(int x){
	if(x < 10)
	   return x % 2 == 0;
	return containsEven(x/10);
}

int main(){
  cout << containsEven(5) << endl;
  cout << containsEven(54) << endl;
  cout << containsEven(5437) << endl;
}
