#include <iostream>
using namespace std;

int main(){
   int h;
   cout << "Please enter your height inches: ";
   cin >> h;
   cout << h/12 << "'" << h%12 << "\"" << endl;
   if(h/12 >= 6)
      cout << "You're tall!";
   return 0;
}
