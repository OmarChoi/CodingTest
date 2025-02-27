#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNode;
	cin >> nNode;
	int rootIndex = 0;
	vector<vector<int>> edges(nNode);
	vector<bool> visit(nNode);
	for (int i = 0; i < nNode; ++i) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			rootIndex = i;
			continue;
		}
		edges[parent].emplace_back(i);
	}
	int deleteNode;
	cin >> deleteNode;

	queue<int> searchNode;
	searchNode.emplace(rootIndex);

	int leafCount = 0;
	while (!searchNode.empty()) {
		int currNode = searchNode.front();
		searchNode.pop();
		if (visit[currNode] == true) continue;
		visit[currNode] = true;

		if (currNode == deleteNode) continue;
		bool connectDeleteNode = false;
		for (int i : edges[currNode]) {
			if (i == deleteNode) {
				connectDeleteNode = true;
				continue;
			}
			searchNode.emplace(i);
		}
		if (edges[currNode].size() == 0 ||
			(connectDeleteNode && edges[currNode].size() == 1)) {
			leafCount += 1;
			continue;
		}
	}
	cout << leafCount;
}