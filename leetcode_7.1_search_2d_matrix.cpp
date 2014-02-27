


bool search2DMatrix(vector<vector<int> > vvi, int target) {
	if(vvi == NULL) {
		return false;
	}
	int first = 0; 
	int	last = vvi.size() * vvi[0].size()-1;
	int width = vvi.size();
	int height = vvi[0].size();
	while(first != last) {
		int mid = first + (last-first)/2;
		int i = mid/height;
		int j = mid%height;

		if(vector[i][j] < target) {
			first = mid+1;
		} else if(vector[i][j] > target{
			last = mid;
		} else {
			return true;
		}
	}
	return false;
}