#include <iostream>
using namespace std;
int main(){
   int x = 15;
   string fred = "Freddy"; 		//
   if (15 >= x)				//
      cout << x % 10 << endl;		// 5
   else
      cout << x / 10 << endl;		//
   if (fred != "Fred" || x < 15)	//
      cout << fred << x % 5 << endl;	// Freddy0
   return 0;
}
