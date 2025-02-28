#include <iostream>
#include <vector>
#include <array>

using namespace std;
array<array<int, 2>, 26> treeArr;

void Preorder(int idx) {
	if (idx < 0) return;
	cout << static_cast<char>(idx + 'A');
	Preorder(treeArr[idx][0]);
	Preorder(treeArr[idx][1]);
}

void Inorder(int idx) {
	if (idx < 0) return;
	Inorder(treeArr[idx][0]);
	cout << static_cast<char>(idx + 'A');
	Inorder(treeArr[idx][1]);
}

void Postorder(int idx) {
	if (idx < 0) return;
	Postorder(treeArr[idx][0]);
	Postorder(treeArr[idx][1]);
	cout << static_cast<char>(idx + 'A');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNode;
	cin >> nNode;
	for (int i = 0; i < nNode; ++i) {
		char currValue, leftValue, rightValue;
		cin >> currValue >> leftValue >> rightValue;
		int currNode = currValue - 'A';

		treeArr[currNode][0] = leftValue - 'A';
		treeArr[currNode][1] = rightValue - 'A';
	}
	Preorder(0);
	cout << "\n";
	Inorder(0);
	cout << "\n";
	Postorder(0);
}