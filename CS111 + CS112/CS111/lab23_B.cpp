#include <iostream>
using namespace std;

int main(){
	int n; 
	cout << "Enter a positive number: ";
	cin >> n;
	
	char letter = 'A';
	cout << letter;
	for(int i = 0; i < n; i++){
		letter = (char)(letter + 1);
		cout << letter;
		if(letter == 'Z'){
			letter = 'A';
			cout << 'A'; 
		}
	}
	return 0; 
}