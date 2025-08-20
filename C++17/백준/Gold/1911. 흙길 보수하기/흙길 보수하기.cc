#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	vector<pair<int, int>> puddles(N);
	for (int i = 0; i < N; ++i) {
		cin >> puddles[i].first >> puddles[i].second;
	}
	sort(puddles.begin(), puddles.end());
	
	int ans = 0;
	int covered = 0; // 지금까지 판자로 덮인 가장 오른쪽 지점 (미포함)

	for (int i = 0; i < puddles.size(); ++i) {
		int s = puddles[i].first;
		int e = puddles[i].second;

		// 이미 덮인 지점까지는 건너뜀
		if (covered < s) covered = s;

		// 덮을 구간 길이
		if (covered < e) {
			int len = e - covered;

			// 웅덩이를 앞에서부터 판자로 채우는 개수 (올림)
			int need = (len + L - 1) / L;

			ans += need;

			// 마지막 판자를 놓고 난 뒤 덮인 지점 업데이트
			covered += need * L;
		}
	}

	cout << ans << '\n';
	return 0;
}
