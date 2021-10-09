#include <iostream>
#include <cmath>
using namespace std;

void print(int q[8], int num);

int main(){
	int q[8], c = 0, num = 0;
	q[0] = 0;
nc:	c++;
	if(c==8) goto print;
	q[c] = -1;
nr:	q[c]++;
	if(q[c] == 8) goto backtrack;
	//test
	for(int i = 0; i < c; i++){
		if(q[i] == q[c] || c-i == abs(q[c]-q[i])) goto nr;
	}
	goto nc;
backtrack:c--;
	  if(c==-1) return 0;
	  goto nr;
print:	num++;
	print(q, num);	
	goto backtrack;
	return 0;
}

void print(int q[8], int num){
	cout<<endl<< "Solution " << num << endl;
	int i, j, k, l;
	typedef char box[5][7];
	box bb, wb, bq, wq, *board[8][8];
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < 7; j++){
			wb[i][j]=' ';
			wq[i][j]=' ';
			bb[i][j]=char(219);
			bq[i][j]=char(219);
		}
	}
	
	wq[1][1] = char(219); bq[1][1] = ' ';
	wq[2][1] = char(219); bq[2][1] = ' ';
	wq[3][1] = char(219); bq[3][1] = ' ';
	wq[3][2] = char(219); bq[3][2] = ' ';
	wq[1][3] = char(219); bq[1][3] = ' ';
	wq[2][3] = char(219); bq[2][3] = ' ';
	wq[3][3] = char(219); bq[3][3] = ' ';
	wq[3][4] = char(219); bq[3][4] = ' ';
	wq[1][5] = char(219); bq[1][5] = ' ';
	wq[2][5] = char(219); bq[2][5] = ' ';
	wq[3][5] = char(219); bq[3][5] = ' ';
	
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if((i+j) % 2 == 0){
				board[i][j] = &wb;
				if(j == q[i]) board[i][j] = &wq;
			}else{
				board[i][j] = &bb;
				if(j == q[i]) board[i][j] = &bq;
			}
		}
	}
	
	cout << "  ";
	for(i = 0; i < 7*8; i++)
		cout << "_";
	cout << endl;
	
	for(i = 0; i < 8; i++)
		for(k = 0; k < 5; k++){
			cout<< "  " << char(179);
			for(j = 0; j < 8; j++)
				for(l = 0; l < 7; l++)
					cout << (*board[i][j])[k][l];
			cout << char(179) << endl;
		}
	
	cout << "  ";
	for(i = 0; i < 7*8; i++)
		cout<<char(196);
	cout<<endl;
	return;
}