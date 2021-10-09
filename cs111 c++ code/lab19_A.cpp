#include <iostream>
using namespace std;

int main(){
   string data[2][3] = {{"1", "2", "3"},
   					    {"11", "12", "21"}};
   cout << data[1][1] << endl;   //output:
   for (int i = 2; i >= 1; i--) cout << data[1][i]; cout << endl; 
   //output: 2112
   return 0;
}


