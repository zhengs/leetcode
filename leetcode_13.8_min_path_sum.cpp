#include <vector>
using namespace std;


int minSum(vector<vector<int> > &vvi) {
	for(int i = 1; i < vvi[0].size();i++) {
		vvi[0][i] += vvi[0][i-1];
	}

	for(int i = 1; i < vvi.size();i++) {
		vvi[i][0] += vvi[i-1][0];
	}

	for(int i = 1; i < vvi.size(); i++) {
		for(int j = 1; j < vvi[0].size(); j++) {
			vvi[i][j] += min(vvi[i-1][j], vvi[i][j-1]);
		}
	}
	return vvi[vvi.size()-1][vvi[0].size()-1];
}