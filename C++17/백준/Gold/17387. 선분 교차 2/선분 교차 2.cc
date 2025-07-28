#include <iostream>
#include <array>

using namespace std;

constexpr int nPoint = 4;

class Point
{
public:
	long long yPos;
	long long xPos;
};
array<Point, nPoint> points;

int CCW(int a, int b, int c) {
	long long rev = (points[a].xPos * points[b].yPos + points[b].xPos * points[c].yPos + points[c].xPos * points[a].yPos)
		- (points[a].xPos * points[c].yPos + points[b].xPos * points[a].yPos + points[c].xPos * points[b].yPos);
	if (rev > 0) return  1;
	if (rev < 0) return -1;
	return 0;
}

bool CheckOverlapped(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
	long long minAX = min(p1.xPos, p2.xPos), maxAX = max(p1.xPos, p2.xPos);
	long long minBX = min(p3.xPos, p4.xPos), maxBX = max(p3.xPos, p4.xPos);
	long long minAY = min(p1.yPos, p2.yPos), maxAY = max(p1.yPos, p2.yPos);
	long long minBY = min(p3.yPos, p4.yPos), maxBY = max(p3.yPos, p4.yPos);

	if (max(minAX, minBX) > min(maxAX, maxBX)) return false;
	if (max(minAY, minBY) > min(maxAY, maxBY)) return false;
	return true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < nPoint; ++i) {
		cin >> points[i].xPos >> points[i].yPos;
	}

	array<array<int, 2>, 2> result{ 0, };
	for (int i = 0; i < nPoint / 2; ++i) {
		// L1를 기준으로 L2의 두 정점이 각각 다른 방향에 있는지 확인 -> 0, 1, 2 // 0, 1, 3 검사
		result[0][i] = CCW(0, 1, i + 2);

		// L2를 기준으로 L1의 두 정점이 각각 다른 방향에 있는지 확인 -> 2, 3, 0 // 2, 3 ,1 검사
		result[1][i] = CCW(2, 3, i);
	}
	

	if (result[0][0] * result[0][1] == 0
		&& result[1][0] * result[1][1] == 0) {
		// 두 선분이 같은 직선 상에 있을 때, 두 선분이 겹치는지 확인
		cout << CheckOverlapped(points[0], points[1], points[2], points[3]);
	}
	else if (result[0][0] * result[0][1] <= 0 
		&& result[1][0] * result[1][1] <= 0) {
		// 한 선분 기준으로 다른 선분의 두 정점이 같은 방향에 있음
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
}
