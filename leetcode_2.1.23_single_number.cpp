#include <iostream>
#include <vector> 
using namespace std;


int main() {
	int a[] = {1,4,2};
	int r = a[0];
	for(int i = 1; i < sizeof(a)/sizeof(*a); i++)
		r = r^a[i];
	cout << r << endl;
}