#include <iostream>
#include <cmath>
using namespace std;

bool test(int cross[], int x) {
  // (static) is globle variable, we can access it whenever we want, doesn't change.
	static int checkList[8][5] = {
    {-1},
		{0,-1},
		{0,1,-1},
		{0,2,-1},
		{1,2,-1},
		{1,2,3,4,-1},
		{2,3,5,-1},
		{4,5,6,-1},
	};
	//fill in
  for (int j = 0; j < x; j++){
    for (int i = 0; checkList[x][i] != -1; i++){
			// If absolute value is less or equals to 1 is not working also check the row test, make sure the numbers don't repeat.
      if (abs(cross[x] - cross[checkList[x][i]]) == 1 || cross[x] == cross[j]){
        return false;
      }
    }
  }
  return true;
}

void print(int cross[], int cap) {
	static int count = 0;
	cout << "Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[4] << endl;
	cout << cross[0] << cross[2] << cross[5] << cross[7] << endl;
	cout << " " << cross[3] << cross[6] << endl << endl;
	return;
}

void move(int * q, int i){
  if (i == 8){
    print(q,i);
    return;
  }
  for (int j = 1; j < 9; j++){
    q[i] = j;
    if (test(q,i)){
      move(q, i+1);
    }
  }
}

int main(){
  int q[8];
  move(q,0);
  system("pause");
}
