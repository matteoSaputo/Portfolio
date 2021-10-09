#include<iostream>
#include<cmath>
using namespace std;

int nQueens(int n);

int main(){
	int n;
	cout<<"How many queens? ";
	cin>>n;
	nQueens(n);
}

int nQueens(int n){
	int c = 0, num = 0, q[n];
	q[0] = 0;
nc:	c++;
	if(c==n) goto print;
	q[c] = -1;
nr:	q[c]++;
	if(q[c] == n) goto backtrack;
	//test
	for(int i = 0; i < c; i++){
		if(q[i] == q[c] || c-i == abs(q[c]-q[i])) goto nr;
	}
	goto nc;
backtrack:c--;
	  if(c==-1){
	  	cout<<"There are "<<num<<" solutions to the "<< n << " queens problem "<<endl;
	  	return 0;
	  } 
	  goto nr;
print:	num++;
	goto backtrack;
	return 0;
}
