#include <iostream>
#include <string>
using namespace std;

int max2(double x, double y){
	if(x > y)
	   return x;
	return y;
}

void printSum(double a, double b){
	cout << a+b;
}

int reverse(int x){
	std::string output = "";
	int y = x;
	while(y > 0){
		output.append(std::to_string(y%10));
		y /= 10;
	}
	return stoi(output);  
}

bool isPrime(int x){
	for(int i = 2; i <= x; i++){
		if(x % i == 0)
			return false;
	}
	return true;
}

int main(){
  int x = 200, y = 119;   
  double a = 3.4, b = 5.6;
  a = max2(a, b); //max2 returns the bigger value of a and b, 5.6 in this example
  
  printSum(a*a, b*b); //printSum prints the sum of a^2 and b^2
  
  cout << reverse(x) << endl; //reverse value of x which is 2
  
  if (isPrime(y)) printSum(y,x);  //prints out y+x if y is a prime number

  //Print first 100 prime number starting from 2.
  return 0;

}