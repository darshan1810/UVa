#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int ctr = 0;
	vector<string> res;
	string temp;

	while(getline(cin, temp)) {
		vector<char> curr;
		for(char c : temp) {
			if(c != '\"')
				curr.push_back(c);
			else if(ctr++ & 1) {
				curr.push_back('\'');
				curr.push_back('\'');
			} else {
				curr.push_back('`');
				curr.push_back('`');
			}
		}
		res.push_back(string(curr.begin(), curr.end()));
	}

	for(string s : res)
		cout << s << endl;

	return 0;
}
