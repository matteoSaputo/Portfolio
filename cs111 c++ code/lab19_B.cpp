#include <iostream>
using namespace std;

int main(){
   string[10] students; double grades[10];
   for(int i = 0; i < 10; i++){
      cin >> students[i];
      cin >> grades[i];
   }

   double h = g[0];
   for(int i = 1; i < 10; i++)
      if(grades[i] > h) h = grades[i];
   for(int i = 0; i < 10; i++)
      if(grades[i] == h) cout << students[i];
   cout << endl;
   return 0;
}
