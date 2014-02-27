#include <iostream>
using namespace std;


int f(int n) {
	if(n == 0) return 1;
	if(n == 1) return 1;
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += f(i) * f(n-1-i);
	return sum;
}


int main() {
	for(int i = 0; i < 10; i++)
	cout << f(i) << endl;
}