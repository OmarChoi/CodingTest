#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void CalculateTime()
{
	int nStructure, nRule;
	cin >> nStructure >> nRule;
	vector<int> buildTime(nStructure);
	vector<int> totalBuildTime(nStructure);
	vector<int> nRequire(nStructure);
	vector<vector<int>> connection(nStructure);

	for (int i = 0; i < nStructure; ++i) {
		cin >> buildTime[i];
	}

	for (int i = 0; i < nRule; ++i) {
		int prev, next;
		cin >> prev >> next;
		connection[prev - 1].emplace_back(next - 1);
		nRequire[next - 1] += 1;
	}
	
	queue<int> buildSeq;
	for (int i = 0; i < nStructure; ++i) {
		if (nRequire[i] == 0) {
			buildSeq.emplace(i);
			totalBuildTime[i] = buildTime[i];
		}
	}

	while (!buildSeq.empty()) {
		int curr = buildSeq.front();
		buildSeq.pop();

		for (int i : connection[curr]) {
			int expectTime = totalBuildTime[curr] + buildTime[i];
			if (totalBuildTime[i] < expectTime) {
				totalBuildTime[i] = expectTime;
			}
			nRequire[i] -= 1;
			if (nRequire[i] == 0) {
				buildSeq.emplace(i);
			}
		}
	}

	int targetStructure;
	cin >> targetStructure;


	cout << totalBuildTime[targetStructure - 1] << "\n";
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nTestCase = 0;
	cin >> nTestCase;

	while (nTestCase > 0) {
		CalculateTime();
		nTestCase -= 1;
	}
}