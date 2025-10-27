#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nType, nPerson;
	std::cin >> nType >> nPerson;

	int minValue = 1;
	int maxValue = 0;

	std::vector<int> makgeolli(nType);
	for (int i = 0; i < nType; ++i) {
		std::cin >> makgeolli[i];
		if (makgeolli[i] > maxValue) {
			maxValue = makgeolli[i];
		}
	}

	if (maxValue == 0) {
		std::cout << "0";
		return 0;
	}

	int answer = 0;
	while (minValue <= maxValue) {
		int64_t midValue = minValue + (maxValue - minValue) / 2;
		int nDivide = 0;

		for (int i = 0; i < nType; ++i) {
			nDivide += makgeolli[i] / midValue;
			if (nDivide > nPerson) {
				break;
			}
		}

		if (nDivide < nPerson) {
			maxValue = midValue - 1;
		}
		else {
			answer = midValue;
			minValue = midValue + 1;
		}
	}

	std::cout << maxValue;
}
