#include <iostream>
using namespace std;

int uniquePath(int i, int j, int imax, int jmax) {
	if(i<0 || i > imax || j < 0 || j > jmax)
		return 0;
	if(i == 0 && j == 0) 
		return 1;
	return uniquePath(i-1,j, imax, jmax) +
		uniquePath(i,j-1,imax,jmax);
}

int main() {
	cout << uniquePath(3, 7, 3, 7);
}