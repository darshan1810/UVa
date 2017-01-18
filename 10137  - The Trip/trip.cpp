#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int n;
	double resp, resn, sum, mean, temp;
	scanf("%d", &n);
	while(n) {
		vector<double> vals(n);
		sum = 0.0;
		for(int i = 0; i < n; i++) {
			scanf("%lf", &vals[i]);
			sum += vals[i];
		}
		mean = sum / n;
		// printf("Mean: %lf\n", mean);
		resp = resn = 0.0;
		for(double val : vals) {
			temp = (double) (long) ((val - mean) * 100.0) / 100.0;
			if(temp > 0)
				resp += temp;
			else
				resn += temp;
		}
		printf("$%.2lf\n", fabs(max(resp, -resn)));
		scanf("%d", &n);
	}
	return 0;
}
