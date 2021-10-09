#include <iostream>
using namespace std; 

void order(int a[], int b, int c){}

void swap(int &a, int &b){}

void fun(int a){}

int magic(bool v, string st){}

int main(){
   int x[3][2] = {1,2,3,4,5,6};
   order(x, 3, 2); 				//ordering value in x
   swap(x[0][0], x[1][1]);  //swap two parameter values
   fun(x[2][0]);  
   bool v = true;
   v = fun(magic(v, "false"));
   return 0;
}