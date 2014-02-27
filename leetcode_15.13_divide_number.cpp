#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int divide(int a, int b) {
	if(a<b){
		return 0;
	}
	int r = 0;
	int d = b;
	while(a>=b) {
		a -= b;
		r++;
	}
}