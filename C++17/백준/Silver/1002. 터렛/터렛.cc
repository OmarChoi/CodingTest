#include <iostream>
#include <array>
#include <cmath>

using namespace std;

class turret
{
public:
	int yPos;
	int xPos;
	int radius;

	bool operator == (const turret& rhs) const {
		if (rhs.xPos != xPos) return false;
		if (rhs.yPos != yPos) return false;
		if (rhs.radius != radius) return false;
		return true;
	}
};

int GetDist(const turret& a, const turret& b) {
	int xDist = a.xPos - b.xPos;
	int yDist = a.yPos - b.yPos;
	return pow(xDist, 2) + pow(yDist, 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nTestCase = 0;
	cin >> nTestCase;

	while (nTestCase > 0) {
		nTestCase -= 1;
		array<turret, 2> turrets;
		for (int i = 0; i < 2; ++i) {
			cin >> turrets[i].xPos >> turrets[i].yPos >> turrets[i].radius;
		}
		if (turrets[0] == turrets[1]) {
			cout << "-1\n"; // 두 점이 만나지 않음
			continue;
		}

		int dist = GetDist(turrets[0], turrets[1]);						// 두 중점 사이 거리 ^ 2
		int sumRadius = pow(turrets[0].radius + turrets[1].radius, 2);	// 반지름 합 ^ 2
		int subRadius = pow(turrets[0].radius - turrets[1].radius, 2);	// 반지름 차 ^ 2

		if (dist == sumRadius || dist == subRadius) {
			cout << "1\n";  // 외접 또는 내접
		}
		else if (dist > sumRadius || dist < subRadius) {
			cout << "0\n";  // 두 원이 떨어짐 또는 내부에 있음
		}
		else {
			cout << "2\n";  // 두 점에서 만남
		}
	}
}