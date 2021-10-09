#include <iostream>
#include <fstream>
using namespace std; 

int main(){
	ifstream in;
	ofstream out;
	
	in.open("input.txt");
	out.open("output.txt");
	
	while(!in.eof()){
		string line = in.get();
		out << in.getline(in, line);
	}
}