#include <iostream>
using namespace std; 

void fillUp(int a[], int b, int c){}

int maxLength(string st[], int a){}

int special(int a[]){}

int fun(int a, int b){}

int main(){
   string st[3] = {"hi", "hello", "welcome"};
   int a[3][4];
   fillUp(a, 3, 4); 			//fill up with user inputs
   cout << maxLength(st, 3); 	//print: 7
   a[2][2] = special(st[1]);
   a[1][1] = fun(special(st[0]), a[2][2]);
   return 0;
}