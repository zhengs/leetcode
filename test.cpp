#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <string>
using namespace std;

void dfs(vector<list<int > > &adjacencyList, vector<int> &path, vector<bool> &visited) {
    for(int i = 0; i < adjacencyList.size(); i++) {
        if(visited[i] == true) {
            continue;
        }
        list<int> &li = adjacencyList[i];
    }
}

int main() {
    srand(time(NULL));
    vector<pair<int, int> > vpii;
    vpii.push_back(pair<int, int>(0, 1));
    vpii.push_back(pair<int, int>(2, 1));
    vpii.push_back(pair<int, int>(0, 2));
    vpii.push_back(pair<int, int>(2, 4));
    vpii.push_back(pair<int, int>(1, 3));
    Graph g;
    g.init(vpii);
    return 0;
}