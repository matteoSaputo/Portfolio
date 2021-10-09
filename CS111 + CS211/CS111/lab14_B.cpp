#include <iostream>
using namespace std;

double quadratic(int a, int b, int c, double x){
	return (a*x*x) + (b*x) + c;
}

int fibonacci(int n){
	int ans = 0;
	int t1 = 0;
	int t2 = 1;
	for(int i = 1; i <= n; i++){
		ans = t1 + t2;
		t1 = t2;
		t2 = ans; 
	}
	return ans;
}

void series(int n){
	for(int i = 0; i <= n; i++){
		cout << fibonacci(i) << " ";
	}
}

int main(){
	cout << quadratic(2, 3, 2, 3.0) << endl;
	
	cout << fibonacci(5) << endl;
	
	series(10);
}