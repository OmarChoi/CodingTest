#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
	int nBuilding = 0;
	cin >> nBuilding;
	long long answer = 0;

	vector<int> buildings(nBuilding);
	stack<pair<int, int>> tallest;
	for (int i = 0; i < nBuilding; ++i) {
		cin >> buildings[i];
	}
	tallest.push(make_pair(buildings[0], 0));

	for (int i = 1; i < nBuilding; ++i) {
		int currHeight = buildings[i];
		while (true) {
			if (tallest.empty()) {
				tallest.push(make_pair(currHeight, i));
				break;
			}
			pair<int, int> lastBuilding = tallest.top();
			if (currHeight >= lastBuilding.first) {
				tallest.pop();
				answer += i - lastBuilding.second - 1;
			}
			else {
				tallest.push(make_pair(currHeight, i));
				break;
			}
		}
	}

	pair<int, int> lastBuilding = tallest.top();
	tallest.pop();
	while (!tallest.empty()) {
		pair<int, int> prevBuilding = tallest.top();
		tallest.pop();
		answer += lastBuilding.second - prevBuilding.second;
	}
	cout << answer;
}