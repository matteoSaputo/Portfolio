#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
	int nums[100]; int count = 0;
	for(int i = 0; i < 100; i++){
		nums[i] = 10 + rand() % 99;
		if(nums[i] % 2 == 0)
			cout << nums[i] << endl;
		if(nums[i] > 50)
			count ++;
	}
	cout << "Amount greater than 50: " << count << endl;
	return 0;
}
	