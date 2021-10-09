#include <iostream>
using namespace std;

void printStars(int x){
    for (int i = 1; i <= x; i++) cout << "*";
}

void printSideTriangle(int x){
	int y = 1;
	bool down = false;
	while(y != 0){
		printStars(y);
		cout << endl;
		if(y < x && !down)
			y++;
		else{
			down = true;
			y--;
		}
	}
}

int main(){
	printSideTriangle(5);
	return 0;
}


