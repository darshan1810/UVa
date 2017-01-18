#include <iostream>
#include <vector>

using namespace std;

void increment(int row, int col, vector< vector<int> >& res) {
	int rows = res.size(), cols = res[0].size();
	int dirs[] = {0, 1, 0, -1, 0};
	int diags[] = {1, 1, -1, -1, 1};
	int r, c;

	for(int i = 0; i < 4; i++) {
		r = row + dirs[i], c = col + dirs[i + 1];
		if(r >= 0 && r < rows && c >=0 && c < cols)
			res[r][c]++;
	}

	for(int i = 0; i < 4; i++) {
		r = row + diags[i], c = col + diags[i + 1];
		if(r >= 0 && r < rows && c >= 0 && c < cols)
			res[r][c]++;
	}
}

int main() {
	int n, m, ctr = 1;
	while(cin >> n >> m && n && m) {
		vector<string> inp(n);
		for(int i = 0; i < n; i++)
			cin >> inp[i];
		vector< vector<int> > res(n, vector<int>(m));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(inp[i][j] == '*')
					increment(i, j, res);

		if(ctr > 1)
			cout << endl;
		cout << "Field #" << ctr << ":" << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(inp[i][j] == '*')
					cout << "*";
				else
					cout << res[i][j];
			}
			cout << endl;
		}
		ctr++;
	}
	return 0;
}
