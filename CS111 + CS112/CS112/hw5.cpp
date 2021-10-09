#include<cmath>
#include<iostream>
using namespace std;

bool ok(int b[][8]){
	int row = 0;
	
	for (int col=7; col>0; col--){ 
		while(b[row][col] != 1){
			row++;
		}
		//row test
		for(int j = 0; j < col; j++){
			if(b[row][j] == 1)
					return false;	
		}
		//up diag test
		for(int j=1;(row-j) > -1 && (col-j) > -1; j++){
			if(b[row-j][col-j] == 1)
					return false;
		}
		//down diag test
		for(int j=1;(row+j) < 8 && (col-j) > -1; j++){
			if(b[row+j][col-j] == 1)
					return false;	
		}		
			
	}
	return true;
}

void print(int b[][8], int count){
	//as discussed in class
	cout << "Solution: " << count << endl;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << b[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main(){
	int board[8][8]={0};
 	int count = 0;
 	for(int i0 =0; i0 <8; i0 ++)
 		for(int i1 =0; i1 <8; i1 ++)
 			for(int i2 =0; i2 <8; i2 ++)
 				for(int i3 =0; i3 <8; i3 ++)
 					for(int i4 =0; i4 <8; i4 ++)
 						for(int i5 =0; i5 <8; i5 ++)
 							for(int i6 =0; i6 <8; i6 ++)
 								for(int i7 =0; i7 <8; i7 ++){
 									// use the indices of the loops to set a configuration in array board
 									board[i0][0]=1;
 									board[i1][1]=1;
 									board[i2][2]=1;
									board[i3][3]=1;
									board[i4][4]=1;
 									board[i5][5]=1;
 									board[i6][6]=1;
 									board[i7][7]=1;
 									
 									// if this configuration is conflict-free, print the count and the board
 									if(ok(board)) print(board, ++count);
 									board[8][8] = {0};
 									
								}
	return 0;
}
