#include <iostream>
using namespace std;

int main(){
   double b, h;
   cout << "Base?";
   cin >> b;
   cout << "Height?";
   cin >> h;
   double area = b * h / 2;
   cout << "The area is" << area << endl;
   return 0;
}
