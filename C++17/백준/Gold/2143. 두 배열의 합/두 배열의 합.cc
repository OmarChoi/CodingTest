#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void GetVec(vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		cin >> vec[i];
	}
}

void CreateSumVec(const vector<int>& vec, vector<long long>& sumVec) {
	sumVec.reserve(vec.size() * (vec.size() + 1) / 2);
	for (int j = 0; j < vec.size(); ++j) {
		long long sum = 0;
		for (int i = j; i < vec.size(); ++i) {
			sum += vec[i];
			sumVec.emplace_back(sum);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int targetNum = 0;
	cin >> targetNum;

	int nA, nB;
	cin >> nA;
	vector<int> aVec(nA);
	vector<long long> aSumVec;
	GetVec(aVec);
	CreateSumVec(aVec, aSumVec);

	cin >> nB;
	vector<int> bVec(nB);
	vector<long long> bSumVec;
	GetVec(bVec);
	CreateSumVec(bVec, bSumVec);
	sort(bSumVec.begin(), bSumVec.end());

	long long answer = 0;
	for (int i = 0; i < aSumVec.size(); ++i) {
		int target = targetNum - aSumVec[i];
		auto lo = lower_bound(bSumVec.begin(), bSumVec.end(), target);
		auto hi = upper_bound(bSumVec.begin(), bSumVec.end(), target);
		answer += (hi - lo);
	}
	cout << answer;
}
