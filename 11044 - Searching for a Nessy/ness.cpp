#include <iostream>

using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		n -= 2, m -= 2;
		if(n % 3)
			n += 3;
		n /= 3;
		if(m % 3)
			m += 3;
		m /= 3;
		cout << n * m << endl;	
	}
	return 0;
}
