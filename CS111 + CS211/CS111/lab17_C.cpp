#include <iostream>
using namespace std;

int digitBar(int x){
	if(x < 10){
	   for(int i = 0; i < x; i++)
	      cout << "*";
	   cout << endl;
	}
	cout << digitBar(x/10);
	return 0;
}

int main(){
   digitBar(12543);
   return 0;
}