#include <vector>
#include <iostream>
using namespace std;


void nqueens(int n, int m, vector<vector<bool> > map, int &count) {
	cout << n << ", " << m << endl;
	if(m==0) {
		count ++;
		return;
	}
	bool cont = false;
	for(int i = 0; i < n; i++) {
		if(map[i][0] == false) {
			cont = true;
			vector<vector<bool> > newMap(n, vector<bool>(m-1, false));
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m-1; j++) {
					newMap[i][j] = map[i][j+1];
				}
			for(int j = 0; j < newMap[0].size(); j++) {
				newMap[i][j] = true;
				if(i+j < n) {
					newMap[i+j][j] = true;
				}
				if(i-j >= 0) {
					newMap[i-j][j] = true;
				}
			}
			nqueens(n, m-1, newMap, count);
		}
	}
	if(cont == false) {
		return;
	}
}

int main() {
	int n = 6;
	vector<vector<bool> > map(n, vector<bool>(n, false));
	int count = 0;
	nqueens(n, n, map, count);
	cout << count << endl;
}