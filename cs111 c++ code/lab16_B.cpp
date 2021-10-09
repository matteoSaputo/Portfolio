#include <iostream>
using namespace std;

int sumDigits(int x){
	if(x < 10)
		return x;
	return sumDigits(x / 10) + x%10;
}

void printReverse(int x){
	if(x < 10){
		cout << x;
		return;
	}
	cout << x%10;
	printReverse(x/10);
}
void printNumWithSpace(int x){
	if(x < 10){
		cout << x;
		return;
	}
	printNumWithSpace(x/10);
	cout << " " << x % 10;
}
int power(int x, int y){
	if(y == 1)
		return x;
	return x * power(x, y-1);
}
int main(){
	cout << sumDigits(1371) << endl << endl;
	printReverse(1371);
	cout << endl << endl;
	printNumWithSpace(1371);
	cout << endl << endl;
	cout << power(2, 3);
	return 0;
}


