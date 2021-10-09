#include <iostream>
using namespace std; 

int main(){
	int nums[8] = {};
	for(int i = 0; i < 8; i++){
		cout << "Enter a # between 0 and 7: ";
		cin >> nums[i]; 
	} 
	
	char a[8][8] = {};
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(j == nums[i])
				a[i][j] = 'Q';
			else
				a[i][j] = '.';
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0; 	
}
