#include <iostream>
#include <cmath>
using namespace std;

void print(int q[], int num);

int main(){
	int q[8], c = 0, num = 0;
	q[0] = 0;
	
	for(c = 1; c < 8; c++){
		for(int r = 0; r <= 8; r++){
			//test
			if(q[c] == 8){
				c--;
				if(c==-1) break;
			}
			for(int i = 0; i < c; i++){
				if(q[i] == q[c] || c-i == abs(q[c]-q[i])) q[c] = r;
			}
		}
	}
	if(c == 8) print(q, ++num);
		
	
}

void print(int q[], int num){
	cout<<endl<< "Solution " << num << endl;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if(j == q[i]) cout<<"1";
				else cout <<"0";
			}
		cout<<endl;
		}	
	return;
}
