#include <iostream>
using namespace std;

int main(){
	int b[8][8] = {0}, row, col=0;
	b[0][0] = 1;

nc: 	col++;
	if(col == 8)
		goto print;
	row = -1;
	nr:	row++;
		if(row == 8) goto backtrack;
		//row test
		for(int i = 0; i < col; i++){
			if(b[row][i] == 1)
				goto nr;	
		}
		//up diag test
		for(int i=1;(row-i) > -1 && (col-i) > -1; i++){
			if(b[row-i][col-i] == 1)
				goto nr;
		}
		//down diag test
		for(int i=1;(row+i) < 8 && (col-i) > -1; i++){
			if(b[row+i][col-i] == 1)
				goto nr;	
		}
		b[row][col] = 1;
		goto nc;
backtrack:col--;
	if(col == -1) return 0; 
	row = 0;
	while(b[row][col] != 1){
		row++;
	}
	b[row][col] = 0;
	goto nr;

print:  cout << endl;
  	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << b[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	goto backtrack;
	return 0;
}

