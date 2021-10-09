#include <iostream>
using namespace std;

void printChars(int x, char c){
    for (int i = 1; i <= x; i++) cout << c;
}

void printDiamond(int x){
	int size = x - 1;
	int stars = 1;
	while(size >= 0){
		printChars(size, ' ');
		printChars(stars, '*');
		printChars(size, ' ');
		size--;
		stars+=2;
		cout << endl;
	}
	size++;
	stars-=2;
	while(size <= x-1){
		size++;
		stars-=2;
		printChars(size, ' ');
		printChars(stars, '*');
		printChars(size, ' ');
		cout << endl;
	}
}

int main(){
	printDiamond(5);
}

