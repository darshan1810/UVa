#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


vector<int> solve(vector< vector<int> >& inp) {
	vector< pair<int, int> > vals;
	multiset<int> height;
	vector<int> res;
	int l, h, r;

	for(vector<int>& triple : inp) {
		l = triple[0];
		h = triple[1];
		r = triple[2];
		vals.push_back({l, -h});
		vals.push_back({r, h});
	}
	sort(vals.begin(), vals.end());
	height.insert(0);
	r = 0, h = 0;

	for(pair<int, int>& val : vals) {
		if(val.second < 0)
			height.insert(-val.second);
		else
			height.erase(height.find(val.second));
		l = val.first;
		h = *(height.rbegin());
		if(h != r) {
			res.push_back(l);
			res.push_back(h);
			r = h;
		}
	}
	return res;
}

int main() {
	vector< vector<int> > inp;
	vector<int> res;
	int l, h, r;
	
	while(scanf("%d%d%d", &l, &h, &r) != EOF)
		inp.push_back({l, h, r});

	res = solve(inp);
	if(!res.empty())
		printf("%d", res[0]);
	for(int i = 1; i < res.size(); i++)
		printf(" %d", res[i]);
	printf("\n");
	return 0;
}
