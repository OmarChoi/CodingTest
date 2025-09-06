#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Ball {
public:
	int idx;
	int color;
	int size;

	bool operator < (const Ball& rhs) const {
		return size < rhs.size;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nBall;
	cin >> nBall;
	vector<Ball> balls(nBall);
	vector<int> answer(nBall);
	unordered_map<int, int> colorMap; // 공 색깔별 누적합

	for (int i = 0; i < nBall; ++i) {
		balls[i].idx = i;
		cin >> balls[i].color >> balls[i].size;
	}

	sort(balls.begin(), balls.end());

	int sum = 0;
	int j = 0;
	for (int i = 0; i < nBall; ++i) {
		if (j >= nBall) {
			break;
		}
		
		const Ball& b = balls[i];

		// 현재 공보다 작은 공 누적하여 합함
		// while문 없이 for문으로만 처리하면 자신과 같은 크기의 공 처리 불가능
		while (balls[j].size < b.size) {
			if (j >= nBall) {
				break;
			}
			sum += balls[j].size;
			colorMap[balls[j].color] += balls[j].size;
			++j;
		}

		// 같은 색은 제외
		answer[b.idx] = sum - colorMap[b.color];
	}

	for (int i = 0; i < nBall; ++i) {
		cout << answer[i] << '\n';
	}
}
