#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> blank;

// i를 기준으로 가장 오른쪽에 비어 있는 공항 값을 저장
int Find(int i) {
	while (blank[i] != i) {
		i = blank[i] = Find(blank[i]);
	}
	return i;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nGate, nPlane;
	cin >> nGate >> nPlane;

	// i기준 비어있는 값을 i로 설정
	blank = vector<int>(nGate + 1);
	std::iota(blank.begin(), blank.end(), 0);

	int answer = 0;
	for (int i = 0; i < nPlane; ++i) {
		int planeIdx = 0;
		cin >> planeIdx;

		int docking = Find(planeIdx);

		// i보다 작은 공항 중에 비어있는 공항이 없는 경우
		if (docking <= 0) {
			break;
		}

		answer += 1;
		blank[docking] = Find(docking - 1);
	}

	cout << answer << endl;
}
