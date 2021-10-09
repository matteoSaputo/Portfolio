#include <iostream>
using namespace std;

int main(){
	int a[20] = {};
	for(int i = 0; i < 20; i++){
		cout <<"Enter a single digit #: ";
		cin >> a[i];
		if(a[i] > 10 || a[i] < -10)
			a[i] %= 10; 
	}
	for(int i = 0; i < 20; i++)
		cout << a[i] << ", ";
	cout << endl;
	return 0;
}