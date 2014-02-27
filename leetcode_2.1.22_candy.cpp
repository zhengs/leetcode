#include <iostream>
#include <vector> 
using namespace std;

int candy(vector<int> children) {
	vector<int> candies;
	int i = 1;
	candies[0] = 1;
	while(i < children.size()) {
		if(children[i] > children[i-1])
			candies[i] = candies[i-1]+1;
		else
			candies[i] = 1;
		i++;
	}
	i = children.size()-2;
	while(i > 0) {
		if(children[i-1] > children[i])
			candies[i-1] = max(candies[i-1], candies[i]+1);
		i++;
	}
	int sum = 0;
	for(int i = 0; i < candies.size(); i++)
		sum += candies[i];
	return sum;
}