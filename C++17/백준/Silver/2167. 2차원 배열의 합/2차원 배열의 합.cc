#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int width, height;
	cin >> height >> width;
	vector<vector<int>> vec(height + 1, vector<int>(width + 1, 0));
	vector<vector<int>> prefixSum(height + 1, vector<int>(width + 1, 0));

	for (int j = 1; j <= height; ++j) {
		for (int i = 1; i <= width; ++i) {
			cin >> vec[j][i];
			prefixSum[j][i] = prefixSum[j - 1][i] + prefixSum[j][i - 1] 
				- prefixSum[j - 1][i - 1] + vec[j][i];
		}
	}

	int nTestCase = 0;
	cin >> nTestCase;

	for (int i = 0; i < nTestCase; ++i) {
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << prefixSum[y2][x2] - prefixSum[y1 - 1][x2] - 
			prefixSum[y2][x1 - 1] + prefixSum[y1 - 1][x1 - 1] << "\n";
	}
}
