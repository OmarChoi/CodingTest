#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	vector<int> ASet(a);
	for (int i = 0; i < a; ++i) {
		cin >> ASet[i];
	}
	sort(ASet.begin(), ASet.end());
	
	vector<int> BSet(b);
	for (int i = 0; i < b; ++i) {
		cin >> BSet[i];
	}
	sort(BSet.begin(), BSet.end());

	int aIndex = 0;
	int bIndex = 0;
	int nDuplicate = 0;

	while (bIndex < b) {
		if (ASet[aIndex] < BSet[bIndex]) {
			aIndex += 1;
			if (aIndex == a) {
				break;
			}
		}
		else if (ASet[aIndex] == BSet[bIndex]) {
			nDuplicate += 1;
			ASet[aIndex] = -1;
			aIndex += 1;
			if (aIndex == a) {
				break;
			}
			bIndex += 1;
		}
		else {
			bIndex += 1;
		}
	}

	cout << ASet.size() - nDuplicate << "\n";
	for (int i : ASet) {
		if (i == -1) continue;
		cout << i << " ";
	}
}