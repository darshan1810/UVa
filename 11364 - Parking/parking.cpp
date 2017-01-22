#include <iostream>
#include <climits>

using namespace std;

int main() {
	int t, n, minval, maxval, temp;
	cin >> t;
	while(t--) {
		minval = INT_MAX;
		maxval = INT_MIN;
		cin >> n;
		while(n--) {
			cin >> temp;
			if(minval > temp)
				minval = temp;
			if(maxval < temp)
				maxval = temp;
		}
		cout << 2 * (maxval - minval) << endl;
	}
	return 0;
}
