#include <iostream>
#include <vector>

int GetLIS(const std::vector<int>& students) {
	std::vector<int> lis;
	lis.reserve(students.size());

	for (int i : students) {
		if (lis.size() != 0) {
			int idx = std::lower_bound(lis.begin(), lis.end(), i) - lis.begin();
			if (idx < lis.size()) {
				lis[idx] = i;
				continue;
			}
		}
		lis.emplace_back(i);
	}

	return lis.size();
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	// LIS 탐색
	// 정렬해야 하는 학생 수 = 전체 학생 수 - LIS에 포함된 학생 수;
	
	int nStudent;
	std::cin >> nStudent;

	std::vector<int> students(nStudent);
	for (int i = 0; i < nStudent; ++i) {
		std::cin >> students[i];
	}

	std::cout << nStudent - GetLIS(students);
}