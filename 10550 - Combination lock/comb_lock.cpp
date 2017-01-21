#include <iostream>

using namespace std;

int main() {
	int s, n1, n2, n3, res;
	cin >> s >> n1 >> n2 >> n3;
	while(s || n1 || n2 || n3) {
		res = 120;
		res += (s - n1 + 40) % 40;
		res += (n2 - n1 + 40) % 40;
		res += (n2 - n3 + 40) % 40;
		res *= 9;
		cout << res << endl;
		cin >> s >> n1 >> n2 >> n3;
	}
	return 0;
}
