#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
   srand(time(0));
   int v[100], gapSum = 0, count[10] = {0};
   for(int i = 0; i < 100; i++){
      v[i] = rand() % 10;
   }
   for(int i = 0; i < 99; i++)
      gapSum += v[i+1] - v[i];

   cout << "average: " << gapSum/99.0 << endl;
   for(int i = 0; i < 100; i++){
      int value = v[i];
      count[value]++;
   }
   cout << endl;
   for(int i = 0; i < 10; i++){
      cout << count << " values are " << i << endl;
   }
   return 0;
}
