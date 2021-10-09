#include <iostream>
using namespace std; 

int main(int argc, char** argv){
   srand(time(0));
   int i = rand() % 10;
   for (int c = i; c > 1; c--) cout << c * c; cout << endl;
   i++;
   cout << i + i << endl;  //print out 10
   cout << (char) (i + 'a');
   //next topic, practice after next lecture.
   cout << i++;
   cout << --i;
   cout << ++argc;
   cout << argv[0] << endl;
   return 0;
}

/* output:

644936251694
18
j993./a.out

*/