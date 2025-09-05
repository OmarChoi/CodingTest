#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cm2nm(int x) {
	return x * 1e+7;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x;
	while (cin >> x) {
		x = cm2nm(x);

		int nLego;
		cin >> nLego;

		vector<int> lego(nLego);
		for (int i = 0; i < nLego; ++i) {
			cin >> lego[i];
		}

		if (nLego < 2) {
			cout << "danger\n";
			continue;
		}

		sort(lego.begin(), lego.end());

		bool canBlock = false;
		for (int i = 0; i < nLego; ++i) {
			int remainBlock = x - lego[i];
			// 이미 작은 블럭들을 확인했으니 큰 블럭을 확인할 필요가 없다.
			if (lego[i] > remainBlock) {
				break;
			}

			int idx = lower_bound(lego.begin(), lego.end(), remainBlock) - lego.begin();
			
			// 알맞는 조각이 없거나 같은 조각을 2번 쓰는 경우 생략
			if (idx == nLego || i == idx) {
				continue;
			}

			if (lego[i] + lego[idx] == x) {
				canBlock = true;
				cout << "yes " << lego[i] << " " << lego[idx] << "\n";
				break;
			}
		}

		if (!canBlock) {
			cout << "danger\n";
		}
	}
}
