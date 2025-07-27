#include <iostream>
#include <array>

using namespace std;

constexpr int nPoint = 3;

class Point
{
public:
	int yPos;
	int xPos;
};

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	array<Point, nPoint> points;
	for (int i = 0; i < nPoint; ++i) {
		cin >> points[i].xPos >> points[i].yPos;
	}

	int plus = 0;
	int minus = 0;
	for (int i = 0; i < nPoint; ++i) {
		plus += points[i % nPoint].xPos * points[(i + 1) % nPoint].yPos;
		minus += points[i % nPoint].yPos * points[(i + 1) % nPoint].xPos;
	}

	if (plus == minus) {
		cout << "0\n";
	}
	else {
		cout << (plus - minus) / abs(plus - minus);
	}
}
