#include <iostream>
using namespace std;

int main(){
    int a[10] = {};
    for(int i = 0; i < 10; i++){
       cout << "Enter a #: ";
       cin >> a[i];
    }
	int	x = a[1] - a[0];
	for(int i = 1; i < 10; i++){
		if(a[i] - a[i-1] < x)
			x = a[i] - a[i-1];
	}
	cout << "Smallest Gap: " << x << endl;
	return 0; 
}
