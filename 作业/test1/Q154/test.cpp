#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin>> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int n;
	cin >> n;
	vector<int> point(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> point[2 * i] >> point[2 * i + 1];
	}
	double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	double c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	if (a + b - c <= 10e-5 || b + c - a <= 10e-5 || a + c - b <= 10e-5) {
		cout << -1 << endl;
		return 0;
	}
	int in = 0, on = 0, out = 0;
	for (int i = 0; i < n; ++i) {
		int x0 = point[2 * i];
		int y0 = point[2 * i + 1];
		double d1 = sqrt(pow(x1 - x0, 2) + pow(y1 - y0 ,2));
		double d2 = sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
		double d3 = sqrt(pow(x3 - x0, 2) + pow(y3 - y0, 2));
		double p = (a + b + c) / 2;
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		double p1 = (a + d1 + d2) / 2;
		double s1 = sqrt(p1 * (p1 - a) * (p1 - d1) * (p1 - d2));
		double p2 = (b + d1 + d3) / 2;
		double s2 = sqrt(p2 * (p2 - b) * (p2 - d1) * (p2 - d3));
		double p3 = (c + d2 + d3) / 2;
		double s3 = sqrt(p3 * (p3 - c) * (p3 - d2) * (p3 - d3));
		if (fabs(s1 + s2 + s3 - s) > 10e-5) {
			out++;
		}
		else if (fabs(s1) <= 10e-5 || fabs(s2) <= 10e-5 || fabs(s3) <= 10e-5) {
			on++;
		}
		else {
			in++;
		}
	}
	cout << in << " " << on << " " << out << endl;
	return 0;
}