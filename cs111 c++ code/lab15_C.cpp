#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int max(int x, int y){
   if (x > y) return x;
   return y;
}

int min(int x, int y){
   if (x < y) return x;
   return y;
}

void resetFirst(int& a, int b, int c, int d){
	int x = max(max(a, b), max(c, d));
	int y = min(min(a, b), min(c, d));
	a = rand() % x + y;
	return;
}

int main(){
	srand(time(0));
	int x = 4;
	cout << x << endl;
	resetFirst(x, 6, 3, 2);
	cout << x;
}
