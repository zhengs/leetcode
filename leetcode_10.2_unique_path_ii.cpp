#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





int uniquePath(int i, int j, int imax, int jmax, 
	unordered_map<string,bool> &obs, 
	vector<vector<int> > &memory) {
	// cout << i << ", " << j << endl;
	if(i<0 || i > imax || j < 0 || j > jmax)
		return 0;
	if(i == 0 && j == 0) 
		return 1;
	if(obs.find(to_string(i) + ", " + to_string(j)) != obs.end())
		return 0;
	if(memory[i][j] >= 0) {
		return memory[i][j];
	}
	else {
		// cout << "hah" << endl;
		int a = uniquePath(i-1, j, imax, jmax, obs, memory);
		int b = uniquePath(i,j-1,imax,jmax, obs, memory);
		if(i-1>=0 && i-1 <= imax)
			memory[i-1][j] = a;
		if(j-1>= 0 && j-1 <= jmax)
			memory[i][j-1] = b;
		return a + b;
	}
}

int uniquePath(int i, int j, int imax, int jmax, unordered_map<string,bool > &obs) {
	// cout << "hah";
	vector<vector<int> > memory(imax+1, vector<int>(jmax+1, -1));
	return uniquePath(i,j,imax,jmax,obs,memory);
}
int main() {
	unordered_map<string, bool> obs;
	obs[to_string(1) + ", " + to_string(3)] = true;
	obs[to_string(2) + ", " + to_string(5)] = true;
	cout << uniquePath(3, 7, 3, 7, obs);
}