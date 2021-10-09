#include <iostream>
#include <cmath>
using namespace std;

//Saputo, Matteo
//CS211 21A/22A Homework 1

bool bothDigitsOdd(int num){
   if(num < 10)
         return false;
   if(num % 2 != 0){
         if(num / 10 % 2 != 0)
                return true;
   }
   return false;
}


int main(){
   int perfectSquare = 0;
   int i = 1;
   while(true){
     perfectSquare = i*i;
     if(bothDigitsOdd(perfectSquare))
            break;
     i++;
   }
   cout << sqrt(perfectSquare) << endl;
}