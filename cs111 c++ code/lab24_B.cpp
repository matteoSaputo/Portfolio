#include <iostream>
using namespace std; 

void fillUp(string st[], int x){}

int update(int x&){}

int magicValue(int x){}

string mystery(string st){}


int main(){
   string st[3];
   fillUp(st, 3);   //read in 3 strings to st
   update(st[1]);   //read in a new string to st[1]
   cout << magicValue(st[1].rfind("st")); //print out negative one
   cout << mystery(mystery(st[1][0]));   //print out Y
   cout << magicValue(update(st[0]));    //print out seven
   return 0;
}
