#include <iostream>
using namespace std;

int main(){
	int nums[10]; int sum;
	for(int i = 0; i < 10; i++){
		cout << "Type a #" << endl;
		cin >> nums[i];
		sum += nums[i];
	}
	int ave = sum/10;
	cout << "Average: " << ave << endl;
	cout << "Numbers greater than average: ";
	for(int i = 0; i < 10; i++){
		if(nums[i] > ave)
			cout << nums[i] << ", ";
	}
	cout << endl;
	return 0;
}