#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nPlate, nSushi, k, coupon;
	cin >> nPlate >> nSushi >> k >> coupon;

	vector<int> sushiVec(nPlate);
	array<int, 30'001> sushi{ 0, };
	sushi[coupon] = 1;

	for (int i = 0; i < nPlate; ++i) {
		cin >> sushiVec[i];
	}

	int frontPointer = 0;
	int backPointer = k - 1;
	int nType = 1;
	int maxType = 1;
	queue<int> connectedSushi;

	for (int i = frontPointer; i <= backPointer; ++i) {
		connectedSushi.emplace(sushiVec[i]);
		if (sushi[sushiVec[i]] == 0) nType += 1;
		sushi[sushiVec[i]] += 1;

		if (nType > maxType) maxType = nType;
	}
	frontPointer += 1;
	backPointer += 1;

	while (backPointer != k - 1) {
		int front = connectedSushi.front();
		connectedSushi.pop();
		
		sushi[front] -= 1;
		if (sushi[front] == 0) nType -= 1;

		connectedSushi.emplace(sushiVec[backPointer]);
		if (sushi[sushiVec[backPointer]] == 0) nType += 1;
		sushi[sushiVec[backPointer]] += 1;

		if (nType > maxType) maxType = nType;

		frontPointer = (frontPointer + 1) % nPlate;
		backPointer = (backPointer + 1) % nPlate;
	}

	cout << maxType;
}