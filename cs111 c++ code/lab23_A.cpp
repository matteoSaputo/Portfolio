#include <iostream>
using namespace std;

void convert(int x[], char y[]&, int z){
	for(int i = 0; i < z; i++){
		y[i] = (char)x[i];
	}
	return;
}

int main(){
   int a[5] = {1,2,3,4,5};
   char b[5];
   convert(a, b, 5);//b has '1','2','3','4','5'
}