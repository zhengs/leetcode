#include <vector>
#include <iostream>
using namespace std;

int removeDups(int A[], int n) {
	if(n == 1)
		return n;
	int idx = 1;
	int i = 1;
	while(i < n) {
		if(A[i] == A[i-1]) {
			i++;
		} else {
			A[idx] = A[i];
			idx++;
			i++;
		}
	}
	return idx;
}


int main() {
	int A[] = {1,1,1,2,2,2,3,1,1,1};
	int l = removeDups(A, sizeof(A)/sizeof(*A));
	for(int i = 0; i < l; i++)
		cout << A[i] << " ";

}