#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string add(string a, string b);

int main(){
	cout <<"Enter a number: ";
	string a, b;
	cin >> a;
	cout <<"Enter a number: ";
	cin >> b;
	while(a != "done" || b != "done"){
		cout << "The sum is: " << add(a, b)<< endl;
		cout << "Enter a number: ";
		cin >> a;
		if(a == "done")
			break;
		cout << "Enter another number: ";
		cin >> b;
	}

	return 0;
}

string add(string a, string b){
	if(a.length() > b.length())
		swap(a, b);
	string output = "";
	reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
	int carry = 0;
	for(int i = 0; i < a.length(); i++){
		int sum = ((a[i]-'0')+(b[i]-'0')+carry);
		output.push_back(sum%10+'0');
		carry = sum/10;
	}
	for(int i = a.length(); i < b.length(); i++){
		int sum = ((b[i]-'0')+carry);
		output.push_back(sum%10+'0');
		carry = sum/10;
	}
	if(carry)
		output.push_back(carry+'0');
	reverse(output.begin(), output.end());
	return output;
}
