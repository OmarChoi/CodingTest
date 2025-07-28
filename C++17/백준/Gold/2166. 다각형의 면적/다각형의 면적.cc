#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nPoint = 0;
	cin >> nPoint;
	vector<int> yPos(nPoint);
	vector<int> xPos(nPoint);
	cin >> xPos[0] >> yPos[0];

	double sum = 0;
	for (int i = 1; i < nPoint; ++i) {
		cin >> xPos[i] >> yPos[i];
		sum += static_cast<double>(yPos[i]) * xPos[i - 1];
		sum -= static_cast<double>(xPos[i]) * yPos[i - 1];
	}
	sum += static_cast<double>(yPos[0]) * xPos[nPoint - 1];
	sum -= static_cast<double>(xPos[0]) * yPos[nPoint - 1];
	sum = abs(sum) / 2;

	cout << fixed << setprecision(1) << sum << "\n";
}
