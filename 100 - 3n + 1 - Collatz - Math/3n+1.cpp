#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <climits>
#define LIM 10004
#define MAXLIM 1006
using namespace std;

int memo[MAXLIM];

int getLength(int val) {
	if(val < MAXLIM && memo[val])
		return memo[val];
	int result = INT_MIN;
	if(val & 1)
		result = 1 + getLength(3 * val + 1);
	else
		result = 1 + getLength(val / 2);
	if(val < MAXLIM)
		memo[val] = result;
	return result;
}

void preprocess() {
	memo[1] = 1;
	for(int i = 1; i < MAXLIM; i++)
		if(!memo[i])
			memo[i] = getLength(i);
}

int maxval(int start, int end) {
	int result = INT_MIN, curr;
	for(int i = start; i <= end; i++) {
		curr = getLength(i);
		if(result < curr)
			result = curr;
	}
	return result;
}

int main() {
	int i, j;
	int l, r;
	
	preprocess();
	while(scanf("%d%d", &i, &j) != EOF) {
		l = min(i, j);
		r = max(i, j);
		printf("%d %d %d\n", i, j, maxval(l, r));
	}
	return 0;
}
