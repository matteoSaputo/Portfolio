#include <iostream>
#include <cmath>
using namespace std;

void print(int q[]);
bool ok(int q[], int index);

int main(){
	int q[8] = {0}, box = 0;
	q[box] = 1;

nc:	box++;
	if(box == 8){
		print(q);
		goto backtrack;
	}
nv:	q[box]++;
	if(q[box] > 8)
		goto backtrack;
	else{
		if(!ok(q, box)) goto nv;
	}
	goto nc;
backtrack:box--;
	  if(box < 0) return 0;

}

void print(int q[8]){
	cout << " " << q[0] << q[1] << endl;
	cout << q[2] << q[3] << q[4] << q[5] << endl;
	cout << " " << q[6] << q[7] << endl;
}

bool ok(int q[], int index){
	int check[8][5] ={ {-1, 0, 0, 0, 0},
		        	   {0, -1, 0, 0, 0},
			   		   {0, -1, 0, 0, 0},
			   		   {0, 1, 2, -1, 0},
			           {0, 1, 3, -1, 0},													     		               
			   		   {1, 4, -1, 0, 0},
			           {2, 3, 4, -1, 0},
			           {3, 4, 5, 6, -1} };
	for(int i=0; i<index; i++){
		if(q[index]==q[i])
		   return false;
	}
	for(int i = 0; check[index][i] < 5; i++){
		if(abs(q[index]-q[check[index][i]]) == 1)
				return false;
	}
	return true;
}
