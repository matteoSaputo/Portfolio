#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int min2(int a, int b){
   if (a < b) return a;
   return b;
}

void readInput(int a){
	cout >> "Enter an integer: ";
	cin << a;
}

bool isPerfectSquare(int a){
	return sqrt((double)a) - sqrt(a) == 0;
}

int min3(int a, int b){
	return min2(a, b);
}

int main(){
   int a, b = 100;
   srand(time(0));
   readInput(a);//read in a value from user and store it to a
   
   if (isPerfectSquare(a)) //check whether value in a is a perfect square
      cout << "You entered a perfect square value." << endl;
   
   if (min3(a, rand() % 100, b / 2) == a)
     cout << "Your input is a small number" << endl;
   
   printPrimeFactorization(a); //Sample a as 36, output: 2^2 X 3^2
   
   return 0;
}