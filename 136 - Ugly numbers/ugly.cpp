#include <iostream>
#include <vector>

using namespace std;

long long int getUgly(int n) {
	int res = 1;
	long long int curr;
	vector<long long int> ctr(6), vals(n);
	vals[0] = 1;
	for(int i = 1; i < n; i++) {
		curr = vals[ctr[2]] * 2;
		curr = min(vals[ctr[3]] * 3, curr);
		curr = min(vals[ctr[5]] * 5, curr);
		if(curr == 2 * vals[ctr[2]])
			ctr[2]++;
		if(curr == 3 * vals[ctr[3]])
			ctr[3]++;
		if(curr == 5 * vals[ctr[5]])
			ctr[5]++;
		vals[i] = curr;
	}
	return vals[n - 1];	
}

int main() {
	int n = 1500;
	cout << "The 1500\'th ugly number is " << getUgly(n) << "." << endl;
	return 0;
}
