#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;
class Edge
{
public:
	int startVertex;
	int endVertex;
	int cost;

	Edge(int s, int e, int c) : startVertex(s), endVertex(e), cost(c) {};
	
	bool operator > (const Edge& other) const {
		return cost > other.cost;
	}
};

int Find(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b)
		parent[b] = a;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nVertex, nEdge;
	cin >> nVertex >> nEdge;

	parent = vector<int>(nVertex + 1);
	vector<bool> connected(nVertex + 1);
	connected[0] = true;

	for (int i = 0; i < nVertex + 1; ++i) {
		parent[i] = i;
	}

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 0; i < nEdge; ++i) {
		int startVertex, endVertex, cost;
		cin >> startVertex >> endVertex >> cost;
		pq.emplace(startVertex, endVertex, cost);
	}

	int edgeCount = 0;
	long long costSum = 0;
	while (edgeCount < nVertex - 1) {
		Edge e = pq.top();
		pq.pop();
		int sv = e.startVertex;
		int ev = e.endVertex;
		if (Find(sv) != Find(ev)) {
			Union(sv, ev);
			costSum += e.cost;
			edgeCount += 1;
		}
	}

	cout << costSum << "\n";
}