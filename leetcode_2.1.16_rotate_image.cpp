#include <vector>
#include <iostream>
using namespace std;


void rotate(vector<vector<int> > *m) {
	int imax = (*m).size();
	int jmax = (*m)[0].size();
	for(int i = 0; i < imax; i++) {
		for(int j = 0; j < jmax; j++)
			swap((*m)[i][j], (*m)[j][i]);
	}
	for(int i = 0; i < imax; i++) {
		for(int j = 0; j < jmax; j++)
			swap((*m)[i][j], (*m)[imax - i - 1][j]);
	}
}

int main() {
	return 0;
}