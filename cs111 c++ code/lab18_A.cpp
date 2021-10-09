#include <iostream>
using namespace std;

int main(){
   string data[3];
   data[0] = "1"; //is this line fine?	yes
   data[1] = "1.1"; //is this line fine?	yes
   data[2] = ""; //is this line fine?	yes
   data[3] = "11"; //is this line fine?	yes
   cout << data[1] << endl;   //output: 1.1
   for (int i = 2; i >= 1; i--) cout << data[i]; cout << endl; 
   //output: 1.1
   return 0;
}
