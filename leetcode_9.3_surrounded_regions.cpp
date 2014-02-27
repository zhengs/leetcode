#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool ifSurrounded(vector<vector<char> > &map, vector<pair<int, int> > &island, int i, int j) {
	if(i<0 || j < 0)  {
		return false;
	}
	if(map[i][j] == 'o') {
		island.push_back(pair<int, int>(i,j));
		bool a = ifSurrounded(map, island, i-1, j);
		bool b = ifSurrounded(map, island, i+1, j);
		bool c = ifSurrounded(map, island, i, j-1);
		bool d = ifSurrounded(map, island, i, j+1);
		return a && b && c && d;
   	}
}
void capture(vector<vector<char> > &map, int m, int n) {
	vector<vector<bool> > visited(map.size(), vector<bool>(map[0].size(), false));
	for(int i = 0; i < map.size(); i++) {
		for(int j = 0; j < map[0].size(); j++){
			if(visited[i][j] == false && map[i][j] == 'o') {
				vector<pair<int, int> > island;
				bool r = ifSurrounded(map, island, i, j);
				if(r == true) {
					for(vector<pair<int, int> >::iterator it = island.begin(); it != island.end(); it++) {
						visited[(*it).first][(*it).second] = true;
						map[(*it).first][(*it).second] = 'x';
					}
				} else {
					island.clear();
				}
			}
		}
	}
}

int main() {

}