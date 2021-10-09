#include <iostream>
using namespace std;
int main(){
   int x, y;
   cout << "First whole number: ";
   cin >> x;
   cout <<"Second whole number: ";
   cin >> y;
   cout << "Average of " << x << " and " << y << " is " << (x+y)/2.0 << endl;
   cout << " The bigger value is ";
   if(x > y)
      cout << x;
   else
      cout << y;
   cout << endl;
   return 0;
}
